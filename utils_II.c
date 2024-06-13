/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/13 18:48:06 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_get(int count)
{
	int		median;

	if (count % 2 != 0)
		median = (count / 2) + 1;
	else
		median = (count + 1) / 2;
	return (median);
}
//cambia questa in una funzione che conta quanti nodi consecutivi sono ordinati
int	reverse_ordered(ps_list *stack)//0 se non ordinata, 1 se ordinata (in ordine inverso)
{
	int		check_order;
	ps_list	*current;

	check_order = 1;
	current = stack;
	while (((current->next) != NULL) && check_order)
	{
		if (*(current ->content) < *((current ->next) ->content))
			check_order = 0;
		current = current->next;
	}
	if (check_order)
		return (1);
	return (0);
}

void	find_target(int	*a, ps_list *stack_b)
{
	ps_list	*current_b;
	ps_list	*target;

	current_b = stack_b;
	target = current_b;
	while (current_b)
	{
		if (*a > *(current_b->content)
			&& ((*a - *(target->content)) < 0
				|| (*a - *(current_b->content)) < (*a - *(target->content))))
			target = current_b;
		current_b = current_b->next;
	}
	if (*a < *(target->content))
	{
		current_b = stack_b;
		while (current_b)
		{
			if (*(current_b->content) > *(target->content))
				target = current_b;
			current_b = current_b->next;
		}
	}
	//printf("t:%d  c:%d", *(target->content), cost_moves(target, ));
}

void	cost_moves(ps_list *node, int position)
{
	int	median;
	int	n_nodes;
	int	odd;
	
	n_nodes = count_stack(ft_lstfirst_bd(node));
	if (n_nodes % 2 == 0)
		odd = 0;
	else
		odd = 1;
	median = median_get(n_nodes);//cambia
	if ((position + odd) <= median)
		node->cost = position;
	else
		node->cost = (position - ((position - median) * 2 + odd));
	printf("A:%d  ", *(node->content));//cancella
	printf("c:%d  ", (node->cost));//cancella
}
