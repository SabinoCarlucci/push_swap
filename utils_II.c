/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 16:42:20 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_get(int count)//mediana = meta' arrotondata per eccesso
{
	int		median;

	if (count % 2 != 0)
		median = (count / 2) + 1;
	else
		median = (count + 1) / 2;
	return (median);
}
//cambia questa in una funzione che conta quanti nodi consecutivi sono ordinati

int	reverse_ordered(t_ps_list *stack)//0 se non ordinata, 1 se ordinata (in ordine inverso)
{
	int		check_order;
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

void	find_target(t_ps_list	*a, t_ps_list *stack_target)
{
	t_ps_list	*current_t;

	current_t = stack_target;
	a->target = current_t;
	while (current_t)
	{
		if (*(a->content) < *(current_t->content)
			&& ((*(a->content) > *(a->target->content))
				|| ( *(current_t->content) - *(a->content))
				< (*(a->target->content) - *(a->content))))
			a->target = current_t;
		current_t = current_t->next;
	}
	/* if (*(a->content) > *(a->target->content))//questa parte non dovrebbe essere necessaria
	{
		current_t = stack_target;
		while (current_t)
		{
			if (*(current_t->content) < *(a->target->content))
				a->target = current_t;
			current_t = current_t->next;
		}
	} */
}

void	total_cost(t_ps_list	*stack)
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
		if ((current->cost_up + current->target->cost_down) <= (current->cost_down + current->target->cost_up))//controlla casistica 3 o 4
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
		//printf("cont:%d  cup:%d  cdown:%d  target:%d  ctot:%d  upd:%d\n", *(current->content), current->cost_up, current->cost_down, *(current->target)->content, current->cost_total, current->up_down);//cancella
		current = current->next;
	}
}

void	set_target_cost(t_ps_list	*stack_st, t_ps_list	*stack_target, int stack_size_st, int stack_size_tar)
{
	t_ps_list	*current;
	int		cost_up;

	current = stack_target;
	cost_up = 0;
	while (current)
	{
		//find_target(current, stack_st);
		current->cost_up = cost_up;
		current->cost_down = stack_size_tar - cost_up;
		cost_up++;
		current = current->next;
	}
	current = stack_st;
	cost_up = 0;
	while (current)//mettere in altra funzione e richiamare due volte
	{
		find_target(current, stack_target);
		current->cost_up = cost_up;
		current->cost_down = (stack_size_st - cost_up);
		cost_up++;
		current = current->next;
	}
	total_cost(stack_st);
}

void	push_chunks2(t_ps_list	**stack_a, t_ps_list	**stack_b, int count, t_moves **stack_moves)
{
	int	n = 1;
	int	step = count / 3;
	int	pushed = 0;
	//int a = 1;
	while (pushed < (count - 3) && !already_ordered(*stack_a))
	{
		if (*((*stack_a)->content) >= n && (*((*stack_a)->content) < (n + step + step)) && *((*stack_a)->content) <= (count - 3))
		{
			pb(stack_a, stack_b, stack_moves);
			//count--;
			pushed++;
		}
		else
		{
			//printf("(%d)", a++);//togli//100 blocca qui
			ra(stack_a, stack_moves);
		}
			
		if (*stack_b && (*stack_b)->content && (count_stack(*stack_b) > 1) && *((*stack_b)->content) >= n && *((*stack_b)->content) < (n + step))
			rb(stack_b, stack_moves);//come evito rb inutili???
		if (pushed == (n + step + step - 1))
		{
			n += (step * 2);
			step = (step/3) + (step % 3);
		}
	}
}

int	make_chunks(int	count)
{
	int	size_chunk;

	size_chunk = 2;
	if ((count - size_chunk) > 0 && (count - size_chunk) < 4)//mettere dentro ciclo?
		return (size_chunk);
	else
		size_chunk = count / 3;
		/*
	while (size_chunk <= 20 && (count / size_chunk) >= size_chunk)
		size_chunk++;*/
	return (size_chunk); 
}

void	make_move(t_ps_list **stack_start, t_ps_list **stack_targ, t_moves **stack_moves)
{
	t_ps_list	*current;
	t_ps_list	*cheapest;

	current = *stack_start;
	cheapest = current;
	while (current)
	{
		if (current->cost_total < cheapest->cost_total)
			cheapest = current;
		current = current->next;
	}
	
	/* if (*((*stack_targ)->content) == *(ft_lstlast_dl(*stack_start))->content + 1)//se consecutivo di testa a e' in fondo a b, pusha quello
		rrb(stack_start);
	else */
		bring_to_top(cheapest, stack_start, stack_targ, stack_moves);
	pa(stack_start, stack_targ, stack_moves);
}

void	last_fix(t_ps_list **stack_a, int count, t_moves **stack_moves)
{
	t_ps_list	*current;
	int		consecutives;
	
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
			rra(stack_a, stack_moves);
	}
	else
	{
		while ((consecutives--) > 0)
			ra(stack_a, stack_moves);
	}
}

/* void total_cost(t_ps_list *stack)
{
    t_ps_list *current;
    int up;
    int down;
    int both;

    current = stack;
    while (current)
    {
        // Determinare il costo up massimo tra nodo corrente e target
        if (current->cost_up >= current->target->cost_up)
            up = current->cost_up;
        else
            up = current->target->cost_up;
        
        // Determinare il costo down massimo tra nodo corrente e target
        if (current->cost_down >= current->target->cost_down)
            down = current->cost_down;
        else
            down = current->target->cost_down;
        
        // Calcolare il costo combinato di up e down
        if (current->cost_up + current->target->cost_down <= current->cost_down + current->target->cost_up)
            both = current->cost_up + current->target->cost_down;
        else
            both = current->cost_down + current->target->cost_up;

        // Determinare l'opzione con il costo minimo
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
        {
            current->cost_total = both;
            if (current->cost_up + current->target->cost_down <= current->cost_down + current->target->cost_up)
                current->up_down = 3;
            else
                current->up_down = 4;
        }

        printf("cont:%d  cup:%d  cdown:%d  target:%d  ctot:%d  upd:%d\n", *(current->content), current->cost_up, current->cost_down, *(current->target->content), current->cost_total, current->up_down);
        current = current->next;
    }
} */

/* void	cost_single_node(t_ps_list *node, int position)//da cambiare completamente
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
	printf("cont:%d  cup:%d  cdown:%d  target:%d\n", *(current->content), current->cost_up, current->cost_down, *(current->target)->content);//cancella
} */