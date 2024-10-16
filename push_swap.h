/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:16:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/10/16 18:54:37 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct dl_list
{
	int				*content;
	struct dl_list	*prev;
	struct dl_list	*next;
	struct dl_list	*target;
	int				cost_up;//se faccio solo rotate
	int				cost_down;//se faccio solo reverse
	int				cost_total;
	int				up_down;//casistica di rotate o reverse o entrambi
}					t_ps_list;

typedef struct t_list
{
	char			*move;
	struct t_list	*next;
}					t_moves;

//start.c
int			count_stack(t_ps_list	*stack);
t_ps_list	*make_lst_from_ints(int argc, char **argv, t_ps_list *stack_a);
t_ps_list	*make_lst_from_string(char **argv, t_ps_list *stack_a);
//node_operations.c 
t_ps_list	*ft_lstnew_dl(void *content);
void		ft_lstadd_front_dl(t_ps_list **lst, t_ps_list *new);
void		ft_lstadd_back_dl(t_ps_list **lst, t_ps_list *new);
t_ps_list	*ft_lstlast_dl(t_ps_list *lst);
t_ps_list	*ft_lstfirst_dl(t_ps_list *lst);
//moves_basic
void		swap(t_ps_list **head);
void		push(t_ps_list **from, t_ps_list **to);
void		rotate(t_ps_list **head);
void		reverse_rotate(t_ps_list **head);
//moves_advanced
void		sa(t_ps_list **stack_a);
void		sb(t_ps_list **stack_b);
void		ss(t_ps_list **stack_a, t_ps_list **stack_b);
void		pa(t_ps_list **stack_b, t_ps_list **stack_a);
void		pb(t_ps_list **stack_a, t_ps_list **stack_b);
void		ra(t_ps_list **stack_a);
void		rb(t_ps_list **stack_b);
void		rr(t_ps_list **stack_a, t_ps_list **stack_b);
void		rra(t_ps_list **stack_a);
void		rrb(t_ps_list **stack_b);
void		rrr(t_ps_list **stack_a, t_ps_list **stack_b);
//checks
int			check_input_repeat(char **argv);
int			check_duplicates(const char *input, const char *input_next);
int			check_num(char *arg);
int			check_limits_int(char *arg);
int			error_message(void);
//utils
void		free_list(t_ps_list *stack);
int			already_ordered(t_ps_list *stack);
void		stack_temp(t_ps_list *stack_a);
void		bubble_sort(t_ps_list	*stack_temp);
void		index_stack_a(t_ps_list *stack_a, t_ps_list *stack_temp);
//utilsII
int			median_get(int count);
int			reverse_ordered(t_ps_list *stack);
void		total_cost(t_ps_list	*stack);
void		compare_cost(t_ps_list	*current, int *both, int *up, int *down);
void		find_target(t_ps_list	*a, t_ps_list *stack_target);
void		set_target_cost(t_ps_list	*stack, t_ps_list	*stack_target,
				int stack_size_st, int stack_size_tar);
void		make_move(t_ps_list **stack_start, t_ps_list **stack_targ);
void		last_fix(t_ps_list **stack_a, int count);
int			size_chunks(int count);
int			make_chunks(int count);
void		update_chunks(t_ps_list **stack_b,
				int *min_chunk, int *step, int *pushed);
//algorithm
void		alg_start(t_ps_list	**stack_a);
void		alg_sort_three(t_ps_list	**stack_a, t_ps_list	**stack_b);
void		alg_sort_three2(t_ps_list	**stack_a, t_ps_list	**stack_b);
void		alg_sort_five(t_ps_list	**stack_a, t_ps_list *stack_b, int median);
void		sort_five_start(t_ps_list **stack_a,
				t_ps_list **stack_b, int median);
void		alg_sort_big(t_ps_list **stack_a, t_ps_list	**stack_b, int count);
void		push_chunks(t_ps_list **stack_a, t_ps_list	**stack_b, int count);
//bring_to_top
void		bring_to_top(t_ps_list *node, t_ps_list **stack_start,
				t_ps_list **stack_targ);
void		move_up(t_ps_list *node, t_ps_list **list1,
				t_ps_list **list2, int double_moves);
void		move_down(t_ps_list *node, t_ps_list **list1,
				t_ps_list **list2, int double_moves);
void		move_up_down(int up_moves, int down_moves,
				t_ps_list **list1, t_ps_list **list2);
void		move_down_up(int down_moves, int up_moves,
				t_ps_list **list1, t_ps_list **list2);
//checker.c
void		check_moves(t_ps_list **stack_a, t_ps_list **stack_b);
void		check_moves_b(char *move, int *stop,
				t_ps_list **stack_a, t_ps_list **stack_b);
void		check_moves_c(char *move, int *stop,
				t_ps_list **stack_a, t_ps_list **stack_b);
//later
//void		print_list(t_ps_list *stack_a);
//void		print_stack(t_ps_list *stack);
//void		print_both_stacks(t_ps_list *stack_a, t_ps_list *stack_b);

#endif