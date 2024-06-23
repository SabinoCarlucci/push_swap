/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:52:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 13:54:11 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_ps_list *node, t_ps_list **stack_start, t_ps_list **stack_targ, t_moves **stack_moves)
{
	if (node->up_down == 1)
		move_up(node, stack_start, stack_targ, stack_moves);
	else if (node->up_down == 2)
		move_down(node, stack_start, stack_targ, stack_moves);
	else if (node->up_down == 3)
		move_up_down(node, stack_start, stack_targ, stack_moves);
	else
		move_down_up(node, stack_start, stack_targ, stack_moves);
}

void	move_up(t_ps_list *node, t_ps_list **list1, t_ps_list **list2, t_moves **stack_moves)
{
	while (node->cost_up != 0 || node->target->cost_up != 0)
	{
		if (node->cost_up != 0)
		{
			rb(list1, stack_moves);
			node->cost_up--;
		}
		if (node->target->cost_up != 0)
		{
			ra(list2, stack_moves);
			node->target->cost_up--;
		}
	}
}

void	move_down(t_ps_list *node, t_ps_list **list1, t_ps_list **list2, t_moves **stack_moves)
{
	while (node->cost_down != 0 || node->target->cost_down != 0)
	{
		if (node->cost_down != 0)
		{
			rrb(list1, stack_moves);
			node->cost_down--;
		}
		if (node->target->cost_down != 0)
		{
			rra(list2, stack_moves);
			node->target->cost_down--;
		}
	}
}

void	move_up_down(t_ps_list *node, t_ps_list **list1, t_ps_list **list2, t_moves **stack_moves)//lista mosse
{
	while (node->cost_up != 0 || node->target->cost_down != 0)
	{
		if (node->cost_up != 0)
		{
			rb(list1, stack_moves);
			node->cost_up--;
		}
		if (node->target->cost_down != 0)
		{
			rra(list2, stack_moves);
			node->target->cost_down--;
		}
	}
}

void	move_down_up(t_ps_list *node, t_ps_list **list1, t_ps_list **list2, t_moves **stack_moves)
{
	while (node->cost_down != 0 || node->target->cost_up != 0)
	{
		if (node->cost_down != 0)
		{
			rrb(list1, stack_moves);
			node->cost_down--;
		}
		if (node->target->cost_up != 0)
		{
			ra(list2, stack_moves);
			node->target->cost_up--;
		}
	}
}
