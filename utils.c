/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:12:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 21:32:00 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	free_list(t_ps_list *stack)
{
	t_ps_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}

void	stack_temp(t_ps_list	*stack_a)
{
	t_ps_list	*stack_temp;
	t_ps_list	*current;
	int			*temp;

	stack_temp = NULL;
	current = stack_a;
	while (current)
	{
		temp = (int *)ft_calloc(1, sizeof(int));
		*temp = *(current ->content);
		ft_lstadd_back_dl(&stack_temp, ft_lstnew_dl(temp));
		current = current->next;
	}
	bubble_sort(stack_temp);
	index_stack_a(stack_a, stack_temp);
	free_list(stack_temp);
	stack_temp = NULL;
}

void	bubble_sort(t_ps_list *stack_temp)
{
	int			temp;
	t_ps_list	*head;

	while (!already_ordered(stack_temp))
	{
		head = stack_temp;
		while (head->next)
		{
			if (*(head->content) > *((head->next)->content))
			{
				temp = *(head->content);
				*(head->content) = *((head->next)->content);
				*((head->next)->content) = temp;
			}
			head = head->next;
		}
	}
}

void	index_stack_a(t_ps_list *stack_a, t_ps_list *stack_temp)
{
	int			index;
	t_ps_list	*current_a;
	t_ps_list	*current_t;

	current_a = stack_a;
	while (current_a)
	{
		index = 1;
		current_t = stack_temp;
		while (current_t)
		{
			if (*(current_a->content) == *(current_t->content))
			{
				*(current_a->content) = index;
				break ;
			}
			index++;
			current_t = current_t->next;
		}
		current_a = current_a->next;
	}
}
