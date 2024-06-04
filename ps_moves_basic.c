/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:35:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/31 19:06:54 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(ps_list **head)//leggi da destra a sinistra per capire
{
	ps_list	*first;
	ps_list	*second;

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
		
	/* if (!*head || !((*head)->next))
		return ;
	(*head)->prev = (*head)->next;//2 diventa prev di 1
	((*head)->next)->prev = NULL;//NULL diventa prev di 2
	if (((*head)->next)->next)//solo se c'e' 3
	{
		(((*head)->next)->next)->prev = *head;//1 diventa prev di 3 (3 e' next di next di 1)
		(*head)->next = ((*head)->prev)->next;//3 diventa successivo di 1
	} else
		(*head)->next = NULL;//next di 1 diventa NULL
	((*head)->prev)->next = (*head);//1 diventa next di 2 (2 e' prev di 1)
	*head = (*head)->prev;//la head passa a 2 */
}

void	push(ps_list **from, ps_list **to)
{
	ps_list *temp;

	if (!from || !*from)
		return;
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
	/* if (from)
	{
		if (!*to)
		{
			(*to) = (*from);
			(*from) = (*from)->next;
			(*to)->next = NULL;
			(*from)->prev = NULL;
			return ;
		}
		(*to)->prev = (*from);
		*from = (*from)->next;//sposto head
		if (*from)
			(*from)->prev = NULL;
		((*to)->prev)->next = (*to);
		*to = (*to)->prev;
	} */
}

void	rotate(ps_list **head)
{
	ps_list *first;
    ps_list *last;

    if (!*head || !(*head)->next)
        return;
    first = *head;
    last = ft_lstlast_bd(*head);

    *head = first->next;
    (*head)->prev = NULL;
    first->next = NULL;
    last->next = first;
    first->prev = last;
	
	/* if (!*head || !((*head)->next))
		return ;
	if (!(((*head)->next)->next))
	{
		swap(head);
		return ;
	}
	(*head)->prev = ft_lstlast_bd(*head);//il prev di 1 diventa 3 (ultimo nodo)
	((ft_lstlast_bd(*head))->next) = (*head);//il next di 3 diventa 1
	*head = (*head)->next;//sposta head su 2
	((*head)->prev)->next = NULL;//il next di 1 diventa NULL
	(*head)->prev = NULL;//il prev di 2 diventa NULL */
}

void	reverse_rotate(ps_list **head)
{
	ps_list	*last;

	if (!*head || !((*head)->next))
		return ;
	last = ft_lstlast_bd(*head);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;	
	
	/* if (!*head || !((*head)->next))
		return ;
	if (!(((*head)->next)->next))
	{
		swap(head);
		return ;
	}
	(*head)->prev = ft_lstlast_bd(*head);//il prev di 1 diventa 3 (ultimo nodo)
	((ft_lstlast_bd(*head))->next) = (*head);//il next di 3 diventa 1
	*head = (*head)->prev;//sposta head su 3
	((*head)->prev)->next = NULL;//il next di 2 diventa NULL
	(*head)->prev = NULL;//il prev di 3 diventa NULL */
}

void	rrr(ps_list **stack_a, ps_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
