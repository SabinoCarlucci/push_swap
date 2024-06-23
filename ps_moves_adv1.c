/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_advanced_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:43:02 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 19:36:39 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps_list **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_ps_list **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_ps_list **stack_a, t_ps_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_ps_list **stack_b, t_ps_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_ps_list **stack_a, t_ps_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
