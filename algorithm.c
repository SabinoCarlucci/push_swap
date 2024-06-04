/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/31 19:40:36 by scarlucc         ###   ########.fr       */
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
		alg_sort_medium(stack_a, count);
}

void	alg_sort_small(ps_list	**stack_a, int	count)
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

void	alg_sort_medium(ps_list	**stack_a, int	count)
{
	ps_list	*stack_b;
	int		median;
	
	stack_b = NULL;
	if (count % 2 != 0)
		median = (count / 2) + 1;
	else
		median = (count + 1) / 2;
	pb(stack_a, &stack_b);
	pb(stack_a, &stack_b);
	print_both_stacks(*stack_a, stack_b);
	//stack_a = NULL;
}
