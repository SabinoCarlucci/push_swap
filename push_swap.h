/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:16:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/04/29 18:01:32 by scarlucc         ###   ########.fr       */
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

typedef struct bd_list
{
	int			*content;
	struct bd_list	*prev;
	struct bd_list	*next;
}					ps_list;

ps_list	*ft_lstnew_bd(void *content);
void	ft_lstadd_front_bd(ps_list **lst, ps_list *new);
void	ft_lstadd_back_bd(ps_list **lst, ps_list *new);
ps_list	*ft_lstlast_bd(ps_list *lst);
void	swap(ps_list **head);
void	push(ps_list **from, ps_list **to);
void	rotate(ps_list **head);
void	reverse_rotate(ps_list **head);
//checks
void print_list(ps_list *stack_a);//cancella prima di consegnare
int		check_input(char **argv, int count);
void	check_num(char *arg);
void	check_limits_int(char *arg);
void	error_message(void);

#endif