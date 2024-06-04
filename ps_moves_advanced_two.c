/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_advanced_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:08:06 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/23 13:44:49 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(ps_list **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(ps_list **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(ps_list **stack_a, ps_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(ps_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(ps_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
