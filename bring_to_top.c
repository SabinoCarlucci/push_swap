/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 09:52:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/19 16:20:26 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(ps_list *node, ps_list **stack_start, ps_list **stack_targ)
{
	int	double_moves;

	if (node->up_down == 1)
	{
		if (node->cost_up > node->target->cost_up)
			double_moves = node->target->cost_up;
		else
			double_moves = node->cost_up;
		move_up(node, stack_start, stack_targ, double_moves);
	}
	else if (node->up_down == 2)
	{
		if (node->cost_down > node->target->cost_down)
			double_moves = node->target->cost_down;
		else
			double_moves = node->cost_down;
		move_down(node, stack_start, stack_targ, double_moves);
	}
	else if (node->up_down == 3)
		move_up_down(node->cost_up, node->target->cost_down, stack_start, stack_targ);
	else
		move_down_up(node->cost_down, node->target->cost_up, stack_start, stack_targ);
}

void	move_up(ps_list *node, ps_list **list1, ps_list **list2, int double_moves)
{
	int	single_moves;
	int	count;
	//int a = 0;//togli

	count = 0;
	if (node->cost_up > double_moves)
		single_moves = node->cost_up  - double_moves;
	else
		single_moves = node->target->cost_up - double_moves;
	while (count < single_moves)
	{
		if (node->cost_up > double_moves)
			rb(list1);
		else
		{
			//printf("(%d)", a++);//togli
			ra(list2);
		}
			
		count++;
	}
	count = 0;
	while (count < double_moves)
	{
		rr(list1, list2);
		count++;
	}
}

void	move_down(ps_list *node, ps_list **list1, ps_list **list2, int double_moves)
{
	int	single_moves;
	int	count;

	count = 0;
	if (node->cost_down > double_moves)
		single_moves = node->cost_down  - double_moves;
	else
		single_moves = node->target->cost_down - double_moves;
	while (count < single_moves)
	{
		if (node->cost_down > double_moves)
			rrb(list1);
		else
			rra(list2);
		count++;
	}
	count = 0;
	while (count < double_moves)
	{
		rrr(list1, list2);
		count++;
	}
}

void	move_up_down(int up_moves, int down_moves, ps_list **list1, ps_list **list2)
{
	int	moves;

	moves = 0;
	while (moves < up_moves)
	{
		rb(list1);
		moves++;
	}
	moves = 0;
	while (moves < down_moves)
	{
		rra(list2);
		moves++;
	}
}

void	move_down_up(int down_moves, int up_moves, ps_list **list1, ps_list **list2)
{
	int	moves;
	//int a = 0;//togli

	moves = 0;
	while (moves < down_moves)
	{
		rrb(list1);
		moves++;
	}
	moves = 0;
	while (moves < up_moves)
	{
		//printf("(%d)", a++);//togli
		ra(list2);
		moves++;
	}
}