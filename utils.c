/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:12:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/13 16:35:37 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(ps_list *stack)
{
	ps_list	*temp;

	//stack = ft_lstfirst_bd(stack);//ho messo questo perche' ci sono problemi con la testa della lista
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}
void    stack_temp(ps_list  *stack_a)//crea stack temporaneo copiando stackA, lo sorta e indicizza stackA
{
	ps_list	*stack_temp;
	ps_list	*current;
	int		*temp;

	stack_temp = NULL;
	current = stack_a;
	while (current)
	{
		temp = (int *)ft_calloc(1, sizeof(int));
		*temp = *(current ->content);
		ft_lstadd_back_bd(&stack_temp, ft_lstnew_bd(temp));
		current = current->next;
	}
	printf("STACK_TEMP\n");//commenta
	print_stack(stack_temp);//commenta
	printf("\n");//commenta
	bubble_sort(stack_temp);
	index_stack_a(stack_a, stack_temp);
	free_list(stack_temp);
	stack_temp = NULL;
}
void	bubble_sort(ps_list  *stack_temp)
{
	int	temp;
	ps_list  *head;

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
	//printf("STACK_TEMP dopo bubble sort\n");//cancella prima di consegna
	//print_stack(stack_temp);//cancella prima di consegna
	//printf("\n");//cancella prima di consegna
}

void	index_stack_a(ps_list  *stack_a, ps_list  *stack_temp)//sostituisce i numeri in stackA con indici
{
	int		index;
	ps_list  *current_a;
	ps_list  *current_t;

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
				break;
			}
			index++;
			current_t = current_t->next;	
		}
		current_a = current_a->next;
	}
}

int	count_stack(ps_list	*stack)//count = numero esatto di nodi
{
	ps_list	*current;
	int		count;
	
	current = stack;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
