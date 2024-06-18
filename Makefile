# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 18:31:23 by scarlucc          #+#    #+#              #
#    Updated: 2024/06/18 09:53:44 by scarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = '\033[0m'
YELLOW = '\033[0;33m'
GREEN = '\033[0;32m'

NAME = push_swap

SRCS = node_operations.c ps_moves_basic.c ps_moves_advanced_one.c ps_moves_advanced_two.c \
		main.c checks.c utils.c utils_II.c algorithm.c bring_to_top.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LIBFT_PATH = Libft/
LIBFT = Libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} push_swap.h
	@echo $(YELLOW) "compiling libft..."$(NO_COLOR)
	@make -C ${LIBFT_PATH} 1>/dev/null
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
	@echo $(GREEN)"compiled libft ✓"$(NO_COLOR)
	@echo $(YELLOW) "compiling push_swap..."$(NO_COLOR)
	@echo $(GREEN)"compiled push_swap ✓"$(NO_COLOR)

test: re
	@gdb push_swap

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ${LIBFT_PATH} 1>/dev/null
	@echo $(YELLOW) "removing .o files..."$(NO_COLOR)
	@rm -f ${OBJS}
	@echo $(GREEN)"removed .o files ✓"$(NO_COLOR)

fclean: clean
	@echo $(YELLOW) "removing NAME file..."$(NO_COLOR)
	@make fclean -C ${LIBFT_PATH} 1>/dev/null
	@rm -f ${NAME}
	@echo $(GREEN)"removed NAME file ✓"$(NO_COLOR)

re: fclean all

.PHONY: all clean fclean