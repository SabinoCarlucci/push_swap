# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:31:23 by scarlucc          #+#    #+#              #
#    Updated: 2024/10/16 18:55:16 by scarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = '\033[0m'
YELLOW = '\033[0;33m'
GREEN = '\033[0;32m'

NAME = push_swap

BONUS_NAME = checker

SRCS = node_operations.c ps_moves_basic.c ps_moves_adv1.c ps_moves_adv2.c \
		start.c checks.c utils.c utils2.c utils3.c algorithm.c bring_to_top.c
OBJS = ${SRCS:.c=.o}

SRCS_BONUS = checker.c
FOLDER_BONUS = bonus/
PATH_BONUS = $(addprefix $(FOLDER_BONUS), $(SRCS_BONUS))
BONUS_OBJS = ${PATH_BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = Libft/
LIBFT = Libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} main.c push_swap.h
	@echo $(YELLOW) "compiling libft..."$(NO_COLOR)
	@make -C ${LIBFT_PATH} 1>/dev/null
	@${CC} ${CFLAGS} ${OBJS} main.c ${LIBFT} -o ${NAME}
	@echo $(GREEN)"compiled libft ✓"$(NO_COLOR)
	@echo $(YELLOW) "compiling push_swap..."$(NO_COLOR)
	@echo $(GREEN)"compiled push_swap ✓"$(NO_COLOR)

${BONUS_NAME}: ${OBJS} ${BONUS_OBJS} push_swap.h
	@echo $(YELLOW) "compiling libft..."$(NO_COLOR)
	@make -C ${LIBFT_PATH} 1>/dev/null
	@${CC} ${CFLAGS} ${OBJS} ${BONUS_OBJS} ${LIBFT} -o ${BONUS_NAME}
	@echo $(GREEN)"compiled libft ✓"$(NO_COLOR)
	@echo $(YELLOW) "compiling checker..."$(NO_COLOR)
	@echo $(GREEN)"compiled checker ✓"$(NO_COLOR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ${LIBFT_PATH} 1>/dev/null
	@echo $(YELLOW) "removing .o files..."$(NO_COLOR)
	@rm -f ${OBJS}
	@rm -f ${BONUS_OBJS}
	@echo $(GREEN)"removed .o files ✓"$(NO_COLOR)

fclean: clean
	@echo $(YELLOW) "removing NAME file..."$(NO_COLOR)
	@make fclean -C ${LIBFT_PATH} 1>/dev/null
	@rm -f ${NAME}
	@rm -f ${BONUS_NAME}
	@echo $(GREEN)"removed NAME file ✓"$(NO_COLOR)

re: fclean all

bonus: ${BONUS_NAME}

rebonus: fclean bonus

test: re 
	gdb ${NAME}

.PHONY: all clean fclean re rebonus test testbonus

.PHONY: all clean fclean