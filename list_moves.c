/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:14:38 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 14:21:04 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_moves(t_moves **stack_moves)
{
	t_moves	*temp;
	t_moves	*counter;

	counter = *stack_moves;
	while (counter && counter->next)
	{
		if ((!ft_strncmp(counter->move, "ra\n", 3) && !ft_strncmp(counter->next->move, "rb\n", 3))
			|| (!ft_strncmp(counter->move, "rb\n", 3) && !ft_strncmp(counter->next->move, "ra\n", 3)))
		{
			temp = counter->next->next;
			free(counter->next);
			counter->move = "rr\n";
			counter->next = temp;
		}
		else if ((!ft_strncmp(counter->move, "rra\n", 4) && !ft_strncmp(counter->next->move, "rrb\n", 4))
			|| (!ft_strncmp(counter->move, "rrb\n", 4) && !ft_strncmp(counter->next->move, "rra\n", 4)))
		{
			temp = counter->next->next;
			free(counter->next);
			counter->move = "rrr\n";
			counter->next = temp;
		}
		else if ((!ft_strncmp(counter->move, "ra\n", 4) && !ft_strncmp(counter->next->move, "rra\n", 4))
			|| (!ft_strncmp(counter->move, "rra\n", 4) && !ft_strncmp(counter->next->move, "ra\n", 4)))
		{
			temp = counter->next->next;
			free(counter->next);
			free(counter);
			
			counter = temp;//annulla ra e rra consecutivi
		}
		counter = counter->next;
	}
}

void	print_moves(t_moves *stack)
{
	while (stack)
	{
		write(1, (stack->move), ft_strlen(stack->move));
		stack = stack->next;
	}
}

void free_list_moves(t_moves *stack)
{
    t_moves *temp;

    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}