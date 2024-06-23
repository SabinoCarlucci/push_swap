/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:35:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/22 20:18:31 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_ps_list **head)//leggi da destra a sinistra per capire
{
	t_ps_list	*first;
	t_ps_list	*second;

	if (!*head || !((*head)->next))//mossa protetta?
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

void	push(t_ps_list **from, t_ps_list **to)
{
	t_ps_list *temp;

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

void	rotate(t_ps_list **head)
{
	t_ps_list *first;
    t_ps_list *last;

    if (!*head || !(*head)->next)
        return;
    first = *head;
    last = ft_lstlast_dl(*head);

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
	(*head)->prev = ft_lstlast_dl(*head);//il prev di 1 diventa 3 (ultimo nodo)
	((ft_lstlast_dl(*head))->next) = (*head);//il next di 3 diventa 1
	*head = (*head)->next;//sposta head su 2
	((*head)->prev)->next = NULL;//il next di 1 diventa NULL
	(*head)->prev = NULL;//il prev di 2 diventa NULL */
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
	
	/* if (!*head || !((*head)->next))
		return ;
	if (!(((*head)->next)->next))
	{
		swap(head);
		return ;
	}
	(*head)->prev = ft_lstlast_dl(*head);//il prev di 1 diventa 3 (ultimo nodo)
	((ft_lstlast_dl(*head))->next) = (*head);//il next di 3 diventa 1
	*head = (*head)->prev;//sposta head su 3
	((*head)->prev)->next = NULL;//il next di 2 diventa NULL
	(*head)->prev = NULL;//il prev di 3 diventa NULL */
}

void	rrr(t_ps_list **stack_a, t_ps_list **stack_b, t_moves **stack_moves)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	//ft_putstr_fd("rrr\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("rra\n"));
}
