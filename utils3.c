/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:45:00 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 22:34:53 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_ordered(t_ps_list *stack)
{
	int			check_order;
	t_ps_list	*current;

	check_order = 1;
	current = stack;
	while (((current->next) != NULL) && check_order)
	{
		if (*(current ->content) < *((current ->next)->content))
			check_order = 0;
		current = current->next;
	}
	if (check_order)
		return (1);
	return (0);
}

int	make_chunks(int count)
{
	int	size_chunk;

	size_chunk = 1;
	if ((count - size_chunk) > 0 && (count - size_chunk) < 4)
		size_chunk = 2;
	else
		size_chunk = count / 3;
	return (size_chunk);
}

void	last_fix(t_ps_list **stack_a, int count)
{
	t_ps_list	*current;
	int			consecutives;

	consecutives = 1;
	current = *stack_a;
	while (*(current)->content == (*(current)->next->content - 1))
	{
		consecutives++;
		current = current->next;
	}
	if (consecutives > (count - consecutives))
	{
		while ((count--) > consecutives)
			rra(stack_a);
	}
	else
	{
		while ((consecutives--) > 0)
			ra(stack_a);
	}
}

void	push_chunks(t_ps_list	**stack_a, t_ps_list	**stack_b, int count)
{
	int	min_chunk;
	int	step;
	int	pushed;

	min_chunk = 1;
	pushed = 0;
	step = make_chunks(count);
	while (pushed < (count - 3) && !already_ordered(*stack_a))
	{
		if (*((*stack_a)->content) >= min_chunk
			&& (*((*stack_a)->content) < (min_chunk + step + step))
			&& *((*stack_a)->content) <= (count - 3))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		update_chunks(stack_b, &min_chunk, &step, &pushed);
	}
}

void	update_chunks(t_ps_list **stack_b, int *min_chunk,
	int *step, int *pushed)
{
	if (*stack_b && (*stack_b)->content && (count_stack(*stack_b) > 1)
		&& *((*stack_b)->content) >= *min_chunk
		&& *((*stack_b)->content) < (*min_chunk + *step))
		rb(stack_b);
	if (*pushed == (*min_chunk + *step + *step - 1))
	{
		*min_chunk += (*step * 2);
		*step = (*step / 3) + (*step % 3);
	}
}
