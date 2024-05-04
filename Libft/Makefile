# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 17:13:38 by scarlucc          #+#    #+#              #
#    Updated: 2024/04/25 14:16:34 by scarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
                    ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
                    ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
                    ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
                    ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
                    ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
                    ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= ${SRCS:.c=.o}

BONUS           = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
                    ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
                    ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS		= ${BONUS:.c=.o}

NAME			= libft.a

CC				= cc

CFLAGS			= -Wall -Werror -Wextra

RM              = rm -f

${NAME}:        ${OBJS} 
				ar rcs ${NAME} ${OBJS}

bonus:			${OBJS} ${BONUS_OBJS}
				ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

all:             ${NAME}

clean:	
				${RM} ${OBJS} ${BONUS_OBJS}

fclean:          clean 
				${RM} ${NAME}

re:              fclean all

.PHONY:			all clean fclean re bonus