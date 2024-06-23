/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_advanced_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:08:06 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/22 19:45:32 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps_list **stack_a, t_moves **stack_moves)
{
	rotate(stack_a);
	//ft_putstr_fd("ra\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("ra\n"));
}

void	rb(t_ps_list **stack_b, t_moves **stack_moves)
{
	rotate(stack_b);
	//ft_putstr_fd("rb\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("rb\n"));
}

void	rr(t_ps_list **stack_a, t_ps_list **stack_b, t_moves **stack_moves)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_lstadd_move(stack_moves, ft_newmove("rr\n"));
	//ft_putstr_fd("rr\n", 1);
}

void	rra(t_ps_list **stack_a, t_moves **stack_moves)
{
	reverse_rotate(stack_a);
	ft_lstadd_move(stack_moves, ft_newmove("rra\n"));
	//ft_putstr_fd("rra\n", 1);
}

void	rrb(t_ps_list **stack_b, t_moves **stack_moves)
{
	reverse_rotate(stack_b);
	ft_lstadd_move(stack_moves, ft_newmove("rrb\n"));
	//ft_putstr_fd("rrb\n", 1);
}
