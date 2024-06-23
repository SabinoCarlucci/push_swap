/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:35:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 19:39:53 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps_list **head)
{
	t_ps_list	*first;
	t_ps_list	*second;

	if (!*head || !((*head)->next))
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*head = second;
}

void	push(t_ps_list **from, t_ps_list **to)
{
	t_ps_list	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	temp->next = *to;
	if (*to)
		(*to)->prev = temp;
	*to = temp;
	if (*to)
		(*to)->prev = NULL;
}

void	rotate(t_ps_list **head)
{
	t_ps_list	*first;
	t_ps_list	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = ft_lstlast_dl(*head);
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void	reverse_rotate(t_ps_list **head)
{
	t_ps_list	*last;

	if (!*head || !((*head)->next))
		return ;
	last = ft_lstlast_dl(*head);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
