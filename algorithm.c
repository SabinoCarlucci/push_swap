/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/05 18:54:35 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_start(ps_list	**stack_a)
{
	int	count;

	count = count_stack(*stack_a);
	if (count < 4)
		alg_sort_small(stack_a, count);
	else
		alg_sort_medium(stack_a, (median_get(count)));
}

void	alg_sort_small(ps_list	**stack_a, int count)
{
	if (count == 2)
		sa(stack_a);
	else
	{
		if (*((*stack_a)->content) == 1)
			rra(stack_a);
		else if (*((*stack_a)->content) == 3 && *(((*stack_a)->next)->content) == 2)
			sa(stack_a);
		if (*((*stack_a)->content) == 3)
			ra(stack_a);
		else if (*((*stack_a)->next->content) == 1)
			sa(stack_a);
		else
			rra(stack_a);
	}	
}

void	sort_medium_start(ps_list	**stack_a, ps_list	**stack_b, int	median)
{
	int		stop;
	
	stop = 0;
	//definisci una variabile che sia la testa della lista
	while (stop < 2)//da ottimizzare: butta in B 
	{
		if (*((*stack_a)->content) < median)
		{
			pb(stack_a, &stack_b);
			stop++;
		}
		else
		{
			if (*((*stack_a)->content) > *((*stack_a)->next->content))
				sa(stack_a);
			else
				ra(stack_a);//metti altre condizioni tipo se due numeri sono consecutivi
		}
	}
}

void	alg_sort_medium(ps_list	**stack_a, int	median)
{
	ps_list	*stack_b;
	stack_b = NULL;

	sort_medium_start//mettilo dentro un ciclo che controlla se ci sono due elementi in b
	print_both_stacks(*stack_a, stack_b);
	if (*((*stack_a)->content) == 5)
	{
		ra(stack_a);
		if (*((*stack_a)->content) == 4)
			sa(stack_a);
	}	
	else if (*((*stack_a)->content) == 4)
	{
		if (*((*stack_a)->next->content) == 5)
			rra(stack_a);
		else
			sa(stack_a);
	}
	else
	{
		if (*((*stack_a)->next->content) == 5)
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
	print_both_stacks(*stack_a, stack_b);
	if (*stack_b->content == 1)
		sb(&stack_b);
	pa(&stack_b, stack_a);
	pa(&stack_b, stack_a);
	print_both_stacks(*stack_a, stack_b);	
	//stack_a = NULL;
}

int	median_get(int count)
{
	int		median;

	if (count % 2 != 0)
		median = (count / 2) + 1;
	else
		median = (count + 1) / 2;
	return (median);
}
