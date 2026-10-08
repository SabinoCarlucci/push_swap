NAME		= push_swap
BONUS_NAME	= checker
 
SRCS		= node_operations.c ps_moves_basic.c ps_moves_adv1.c \
			  ps_moves_adv2.c start.c checks.c utils.c utils2.c utils3.c \
			  algorithm.c bring_to_top.c
MAIN_SRC	= main.c
BONUS_SRC	= bonus/checker.c
 
OBJS		= $(SRCS:.c=.o)
MAIN_OBJ	= $(MAIN_SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)
 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
 
LIBFT_PATH	= Libft
LIBFT		= $(LIBFT_PATH)/libft.a
 
YELLOW		= \033[0;33m
GREEN		= \033[0;32m
NO_COLOR	= \033[0m
 
all: $(NAME)
 
$(NAME): $(LIBFT) $(OBJS) $(MAIN_OBJ)
	@printf "$(YELLOW)linking $(NAME)...$(NO_COLOR)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)$(NAME) ready ✓$(NO_COLOR)\n"
 
bonus: $(BONUS_NAME)
 
$(BONUS_NAME): $(LIBFT) $(OBJS) $(BONUS_OBJ)
	@printf "$(YELLOW)linking $(BONUS_NAME)...$(NO_COLOR)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)
	@printf "$(GREEN)$(BONUS_NAME) ready ✓$(NO_COLOR)\n"
 
$(LIBFT):
	@printf "$(YELLOW)compiling libft...$(NO_COLOR)\n"
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@printf "$(GREEN)libft ready ✓$(NO_COLOR)\n"
 
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null
	@rm -f $(OBJS) $(MAIN_OBJ) $(BONUS_OBJ)
	@printf "$(GREEN)object files removed ✓$(NO_COLOR)\n"
 
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null
	@rm -f $(NAME) $(BONUS_NAME)
	@printf "$(GREEN)binaries removed ✓$(NO_COLOR)\n"
 
re: fclean all
 
rebonus: fclean bonus
 
.PHONY: all bonus clean fclean re rebonus