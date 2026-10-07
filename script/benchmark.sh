#!/bin/bash
# ============================================================================ #
#  benchmark.sh - measure how many moves push_swap needs on random inputs
#
#  Usage:   ./script/benchmark.sh [NUMBERS] [RUNS] [SEED]
#
#    NUMBERS  how many values to sort in each run (default: 100 and 500)
#    RUNS     how many random inputs to try per size (default: 500)
#    SEED     optional, makes the random inputs reproducible
#
#  Examples:
#    ./script/benchmark.sh              # 100 and 500 numbers, 500 runs each
#    ./script/benchmark.sh 500 2000     # 500 numbers, 2000 runs
#    ./script/benchmark.sh 100 1000 42  # same inputs every time
#
#  For every size it prints the minimum, average and maximum number of moves,
#  checks each result with ./checker and saves the best and the worst input
#  in script/benchmark_results/, so a result can be replayed with:
#    ./push_swap $(cat script/benchmark_results/worst_500.txt) | wc -l
# ============================================================================ #

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
RESULTS="$ROOT/script/benchmark_results"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

SIZES="${1:-100 500}"
RUNS="${2:-500}"
SEED="${3:-}"

is_positive_int() { [[ "$1" =~ ^[1-9][0-9]*$ ]]; }

for size in $SIZES; do
	if ! is_positive_int "$size"; then
		echo "Error: NUMBERS must be a positive integer (got '$size')" >&2
		exit 1
	fi
done
if ! is_positive_int "$RUNS"; then
	echo "Error: RUNS must be a positive integer (got '$RUNS')" >&2
	exit 1
fi
if [ -n "$SEED" ] && ! [[ "$SEED" =~ ^[0-9]+$ ]]; then
	echo "Error: SEED must be a non-negative integer (got '$SEED')" >&2
	exit 1
fi

# Build push_swap and checker if they are missing.
cd "$ROOT" || exit 1
[ -x ./push_swap ] || make >/dev/null || { echo "Error: could not build push_swap" >&2; exit 1; }
[ -x ./checker ] || make bonus >/dev/null || { echo "Error: could not build checker (make bonus)" >&2; exit 1; }

mkdir -p "$RESULTS"

# Prints N unique pseudo-random integers in [-10000000, 10000000] on one line.
# Uses awk only, so it also works where `shuf` is not installed. awk's own
# rand() is not repeatable on every awk, so a small Park-Miller generator
# is used: the same seed always gives the same numbers.
random_input() {
	awk -v n="$1" -v seed="$2" 'BEGIN {
		state = seed % 2147483646 + 1;
		for (i = 0; i < 8; i++)
			state = (state * 16807) % 2147483647;
		while (count < n) {
			state = (state * 16807) % 2147483647;
			v = (state % 20000001) - 10000000;
			if (!(v in seen)) { seen[v] = 1; printf "%d ", v; count++ }
		}
		printf "\n"
	}'
}

failed=0

for size in $SIZES; do
	min=""; max=""; sum=0; ko=0
	base_seed="${SEED:-$RANDOM$RANDOM}"
	echo "Testing $size numbers, $RUNS runs..."
	start=$SECONDS
	for ((i = 1; i <= RUNS; i++)); do
		random_input "$size" $((base_seed * 100003 + i)) >"$TMP/input"
		args="$(cat "$TMP/input")"
		# shellcheck disable=SC2086
		./push_swap $args >"$TMP/moves" 2>"$TMP/err"
		if [ -s "$TMP/err" ]; then
			echo "  push_swap printed an error on run $i:" >&2
			cat "$TMP/err" >&2
			cp "$TMP/input" "$RESULTS/error_${size}.txt"
			failed=1
			ko=$((ko + 1))
			continue
		fi
		# shellcheck disable=SC2086
		verdict="$(./checker $args <"$TMP/moves" 2>&1)"
		if [ "$verdict" != "OK" ]; then
			ko=$((ko + 1))
			cp "$TMP/input" "$RESULTS/ko_${size}.txt"
			failed=1
			continue
		fi
		moves=$(wc -l <"$TMP/moves" | tr -d ' ')
		sum=$((sum + moves))
		if [ -z "$min" ] || [ "$moves" -lt "$min" ]; then
			min=$moves; cp "$TMP/input" "$RESULTS/best_${size}.txt"
		fi
		if [ -z "$max" ] || [ "$moves" -gt "$max" ]; then
			max=$moves; cp "$TMP/input" "$RESULTS/worst_${size}.txt"
		fi
	done
	ok=$((RUNS - ko))
	echo "  runs sorted correctly : $ok / $RUNS"
	if [ "$ok" -gt 0 ]; then
		echo "  moves  min / avg / max : $min / $((sum / ok)) / $max"
		echo "  best input  : script/benchmark_results/best_${size}.txt"
		echo "  worst input : script/benchmark_results/worst_${size}.txt"
	fi
	[ "$ko" -gt 0 ] && echo "  WARNING: $ko run(s) failed, input saved in script/benchmark_results/"
	echo "  time: $((SECONDS - start))s"
	echo
done

exit "$failed"
