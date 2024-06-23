/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_advanced_one.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:43:02 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/22 19:45:27 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps_list **stack_a, t_moves **stack_moves)
{
	swap(stack_a);
	//ft_putstr_fd("sa\n", 1);//cambia tutte cosi', altrimenti stesso errore di error_message()
	ft_lstadd_move(stack_moves, ft_newmove("sa\n"));
}

void	sb(t_ps_list **stack_b, t_moves **stack_moves)
{
	swap(stack_b);
	//ft_putstr_fd("sb\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("sb\n"));
}

void	ss(t_ps_list **stack_a, t_ps_list **stack_b, t_moves **stack_moves)
{
	swap(stack_a);
	swap(stack_b);
	//ft_putstr_fd("ss\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("ss\n"));
}

void	pa(t_ps_list **stack_b, t_ps_list **stack_a, t_moves **stack_moves)
{
	push(stack_b, stack_a);
	//ft_putstr_fd("pa\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("pa\n"));
}

void	pb(t_ps_list **stack_a, t_ps_list **stack_b, t_moves **stack_moves)
{
	push(stack_a, stack_b);
	//ft_putstr_fd("pb\n", 1);
	ft_lstadd_move(stack_moves, ft_newmove("pb\n"));
}
