/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 21:23:46 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_cost(t_ps_list *stack_st, t_ps_list *stack_target,
	int stack_size_st, int stack_size_tar)
{
	t_ps_list	*current;
	int			cost_up;

	current = stack_target;
	cost_up = 0;
	while (current)
	{
		current->cost_up = cost_up;
		current->cost_down = stack_size_tar - cost_up;
		cost_up++;
		current = current->next;
	}
	current = stack_st;
	cost_up = 0;
	while (current)
	{
		find_target(current, stack_target);
		current->cost_up = cost_up;
		current->cost_down = (stack_size_st - cost_up);
		cost_up++;
		current = current->next;
	}
	total_cost(stack_st);
}

void	find_target(t_ps_list	*a, t_ps_list *stack_target)
{
	t_ps_list	*current_t;

	current_t = stack_target;
	a->target = current_t;
	while (current_t)
	{
		if (*(a->content) < *(current_t->content)
			&& ((*(a->content) > *(a->target->content))
				|| (*(current_t->content) - *(a->content))
				< (*(a->target->content) - *(a->content))))
			a->target = current_t;
		current_t = current_t->next;
	}
}

void	total_cost(t_ps_list	*stack)
{
	t_ps_list	*current;
	int			up;
	int			down;
	int			both;

	current = stack;
	while (current)
	{
		if (current->cost_up >= current->target->cost_up)
			up = current->cost_up;
		else
			up = current->target->cost_up;
		if (current->cost_down >= current->target->cost_down)
			down = current->cost_down;
		else
			down = current->target->cost_down;
		compare_cost(current, &both, &up, &down);
		current = current->next;
	}
}

void	compare_cost(t_ps_list	*current, int *both, int *up, int *down)
{
	if ((current->cost_up + current->target->cost_down)
		<= (current->cost_down + current->target->cost_up))
	{
		*both = (current->cost_up + current->target->cost_down);
		current->up_down = 3;
	}
	else
	{
		*both = (current->cost_down + current->target->cost_up);
		current->up_down = 4;
	}
	if (*up <= *down && *up <= *both)
	{
		current->cost_total = *up;
		current->up_down = 1;
	}
	else if (*down <= *up && *down <= *both)
	{
		current->cost_total = *down;
		current->up_down = 2;
	}
	else
		current->cost_total = *both;
}

/* void	total_cost(t_ps_list	*stack)
{
	t_ps_list	*current;
	int		up;
	int		down;
	int		both;

	current = stack;
	while (current)
	{
		if (current->cost_up >= current->target->cost_up)
			up = current->cost_up;
		else
			up = current->target->cost_up;
		if (current->cost_down >= current->target->cost_down)
			down = current->cost_down;
		else
			down = current->target->cost_down;
		if ((current->cost_up + current->target->cost_down) 
		<= (current->cost_down + current->target->cost_up))
		{
			both = (current->cost_up + current->target->cost_down);
			current->up_down = 3;
		}
		else
		{
			both = (current->cost_down + current->target->cost_up);
			current->up_down = 4;
		}
		
		if (up <= down && up <= both)
		{
			current->cost_total = up;
			current->up_down = 1;
		}
		else if (down <= up && down <= both)
		{
			current->cost_total = down;
			current->up_down = 2;
		}
		else
			current->cost_total = both;
		//printf("cont:%d  cup:%d  cdown:%d  target:%d  ctot:%d  upd:%d\n", 
		*(current->content), current->cost_up, current->cost_down, 
		*(current->target)->content, 
		current->cost_total, current->up_down);//cancella
		current = current->next;
	}
} */

/* void	cost_single_node(t_ps_list *node, int position)
{
	int	median;
	int	n_nodes;
	int	odd;
	
	n_nodes = count_stack(ft_lstfirst_dl(node));
	if (n_nodes % 2 == 0)
		odd = 0;
	else
		odd = 1;
	median = median_get(n_nodes);//cambia
	if ((position + odd) <= median)
	{
		node->cost = position;
		node->median = 1;//potrebbe cambiare per i numeri pari, controlla dopo
	}
	else
	{
		node->cost = (position - ((position - median) * 2 + odd));
		node->median = 0;
	}
	printf("cont:%d  cup:%d  cdown:%d  target:%d\n", *(current->content), 
	current->cost_up, current->cost_down, *(current->target)->content);//cancella
} */