/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 21:49:29 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_start(t_ps_list	**stack_a)
{
	int			count;
	t_ps_list	**stack_b;

	stack_b = (t_ps_list **)malloc(sizeof(t_ps_list *));
	if (stack_b)
		*stack_b = NULL;
	count = count_stack(*stack_a);
	if (count == 2)
		sa(stack_a);
	else if (count < 4)
		alg_sort_three(stack_a, stack_b);
	else
		alg_sort_big(stack_a, stack_b, count);
	free(stack_b);
}

void	alg_sort_three(t_ps_list	**stack_a, t_ps_list	**stack_b)
{
	if ((*((*stack_a)->content) < *((*stack_a)->next->content))
		&& (*((*stack_a)->content) < *((*stack_a)->next->next->content)))
		rra(stack_a);
	else if ((*((*stack_a)->content) > *((*stack_a)->next->content))
		&& (*((*stack_a)->next->content)
			> *((*stack_a)->next->next->content)))
	{
		if ((count_stack(*stack_b) > 1)
			&& (*(*stack_b)->content < *(*stack_b)->next->content))
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
	alg_sort_three2(stack_a, stack_b);
}

void	alg_sort_three2(t_ps_list	**stack_a, t_ps_list	**stack_b)
{
	if ((*((*stack_a)->content) > *((*stack_a)->next->content))
		&& (*((*stack_a)->content) > *((*stack_a)->next->next->content)))
		ra(stack_a);
	else if ((*((*stack_a)->next->content) < *((*stack_a)->content))
		&& (*((*stack_a)->next->content)
			< *((*stack_a)->next->next->content)))
	{
		if ((count_stack(*stack_b) > 1)
			&& (*(*stack_b)->content < *(*stack_b)->next->content))
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
	else
		rra(stack_a);
}

void	alg_sort_big(t_ps_list **stack_a, t_ps_list	**stack_b, int count)
{
	int	stack_size_st;
	int	stack_size_tar;

	push_chunks(stack_a, stack_b, count);
	stack_size_st = count_stack(*stack_b);
	stack_size_tar = count_stack(*stack_a);
	if (!already_ordered(*stack_a) && stack_size_tar > 1)
	{
		if (stack_size_tar == 2)
			sa(stack_a);
		else
			alg_sort_three(stack_a, stack_b);
	}
	while (*stack_b && (*stack_b)->content)
	{
		set_target_cost(*stack_b, *stack_a, stack_size_st--, stack_size_tar++);
		make_move(stack_b, stack_a);
	}
	if (!already_ordered(*stack_a))
		last_fix(stack_a, count);
}

void	make_move(t_ps_list **stack_start, t_ps_list **stack_targ)
{
	t_ps_list	*current;
	t_ps_list	*cheapest;

	current = *stack_start;
	cheapest = current;
	while (current)
	{
		if (current->cost_total < cheapest->cost_total)
			cheapest = current;
		current = current->next;
	}
	bring_to_top(cheapest, stack_start, stack_targ);
	pa(stack_start, stack_targ);
}
