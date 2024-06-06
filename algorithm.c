/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/06 19:16:48 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_start(ps_list	**stack_a)
{
	int	count;

	count = count_stack(*stack_a);
	if (count < 4)
		alg_sort_three(stack_a, count);
	else if (count == 5)//altri if per altri numeri
		alg_sort_five(stack_a, (median_get(count)));
}

void	alg_sort_three(ps_list	**stack_a, int count)//rinomina con small
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
	}//qui chiama algoritmo per 5
}

void	sort_five_start(ps_list **stack_a, ps_list **stack_b, int median)
{
	ps_list	*last;

	last = ft_lstlast_bd(*stack_a);
	if (*last->content == 1)
		rra(stack_a);
	if (*((*stack_a)->content) < median)
		pb(stack_a, stack_b);//altro if che forse fa swap
	else
	{
		if (*((*stack_a)->content) > *((*stack_a)->next->content))
		{
			if (*((*stack_a)->next->content) > median)
				sa(stack_a);
			ra(stack_a);
		}
		else
			ra(stack_a);//metti altre condizioni tipo se due numeri sono consecutivi
	}
}

void	alg_sort_five(ps_list	**stack_a, int	median)
{
	ps_list	*stack_b;
	stack_b = NULL;

	while (count_stack(stack_b) < 2)
		sort_five_start(stack_a, &stack_b, median);
	if (*((*stack_a)->content) == 5)
		ra(stack_a);	
	else if (*((*stack_a)->content) == 4)
	{
		if (*((*stack_a)->next->content) == 5)
			rra(stack_a);
		else
			sa(stack_a);
	}
	else if (*((*stack_a)->next->content) == 5)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (!reverse_ordered(stack_b))
		sb(&stack_b);
	while (stack_b)
		pa(&stack_b, stack_a);
}
