/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/17 19:07:41 by scarlucc         ###   ########.fr       */
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

int	reverse_ordered(ps_list *stack)//0 se non ordinata, 1 se ordinata (in ordine inverso)
{
	int		check_order;
	ps_list	*current;

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

void	find_target(ps_list	*a, ps_list *stack_target)
{
	ps_list	*current_t;

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
	if (*(a->content) > *(a->target->content))
	{
		current_t = stack_target;
		while (current_t)
		{
			if (*(current_t->content) < *(a->target->content))
				a->target = current_t;
			current_t = current_t->next;
		}
	}
}

void	total_cost(ps_list	*stack)
{
	ps_list	*current;
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

void	set_target_cost(ps_list	*stack, ps_list	*stack_target, int stack_size_st, int stack_size_tar)
{
	ps_list	*current;
	int		cost_up;

	current = stack;
	cost_up = 0;
	while (current)
	{
		find_target(current, stack_target);//forse togliere position tra i parametri
		current->cost_up = cost_up;
		current->cost_down = (stack_size_st - cost_up);
		cost_up++;
		current = current->next;
	}
	current = stack_target;
	cost_up = 0;
	while (current)
	{
		find_target(current, stack);//forse togliere position tra i parametri
		current->cost_up = cost_up;
		current->cost_down = stack_size_tar - cost_up;
		cost_up++;
		current = current->next;
	}
	total_cost(stack);
}

void	push_chunks(ps_list	**stack_a, ps_list	**stack_b, int count)
{
	int	max;
	int	step;
	int	n;
	int	pushed;

	max = count - 3;
	step = max / 8;
	n = 1;
	pushed = 0;
	while (count_stack(*stack_a) > 3)
	{
		if (*((*stack_a)->content) >= n && *((*stack_a)->content) < (n + step) && *((*stack_a)->content) <= max)//se nodo e' nello stack, pushalo in b, altrimenti rotate
		{
			pb(stack_a, stack_b);
			pushed++;
			if (pushed == step)
			{
				n += step;
				pushed = 0;
			}
		}
		else
			ra(stack_a);
	}
	while ((*stack_a)->prev != NULL)//queste 4 righe forse vanno altrove, forse non servono piu'
		*stack_a = (*stack_a)->prev;
	while ((*stack_b)->prev != NULL)
		*stack_b = (*stack_b)->prev;
}

void	make_move(ps_list **stack_start, ps_list **stack_targ)
{
	ps_list	*current;
	ps_list	*cheapest;

	current = *stack_start;
	cheapest = current;
	while (current)
	{
		if (current->cost_total < cheapest->cost_total)
			cheapest = current;
		current = current->next;
	}
	bring_to_top(cheapest, stack_start, stack_targ);
	pa(stack_start, stack_targ);
}

void	bring_to_top(ps_list *node, ps_list **stack_start, ps_list **stack_targ)
{
	int	double_moves;

	if (node->up_down == 1)
	{
		if (node->cost_up > node->target->cost_up)
			double_moves = node->target->cost_up;
		else
			double_moves = node->cost_up;
		move_up(node, stack_start, stack_targ, double_moves);
	}
	else if (node->up_down == 2)
	{
		//return;
		if (node->cost_down > node->target->cost_down)
			double_moves = node->target->cost_down;
		else
			double_moves = node->cost_down;
		move_down(node, stack_start, stack_targ, double_moves);
	}
	else if (node->up_down == 3)
		//return;
		move_up_down(node->cost_up, node->target->cost_down, stack_start, stack_targ);
	else
		//return;
		move_down_up(node->cost_down, node->target->cost_up, stack_start, stack_targ);
}

void	move_up(ps_list *node, ps_list **list1, ps_list **list2, int double_moves)
{
	int	single_moves;
	int	count;

	count = 0;
	if (node->cost_up > double_moves)
		single_moves = node->cost_up  - double_moves;
	else
		single_moves = node->target->cost_up - double_moves;
	while (count < single_moves)
	{
		if (node->cost_up > double_moves)
			rb(list1);
		else
			ra(list2);
		count++;
	}
	count = 0;
	while (count < double_moves)
	{
		rr(list1, list2);
		count++;
	}
}

void	move_down(ps_list *node, ps_list **list1, ps_list **list2, int double_moves)
{
	int	single_moves;
	int	count;

	count = 0;
	if (node->cost_down > double_moves)
		single_moves = node->cost_down  - double_moves;
	else
		single_moves = node->target->cost_down - double_moves;
	while (count < single_moves)
	{
		if (node->cost_down > double_moves)
			rrb(list1);
		else
			rra(list2);
		count++;
	}
	count = 0;
	while (count < double_moves)
	{
		rrr(list1, list2);
		count++;
	}
}

void	move_up_down(int up_moves, int down_moves, ps_list **list1, ps_list **list2)
{
	int	moves;

	moves = 0;
	while (moves < up_moves)
	{
		rb(list1);
		moves++;
	}
	moves = 0;
	while (moves < down_moves)
	{
		rra(list2);
		moves++;
	}
}

void	move_down_up(int down_moves, int up_moves, ps_list **list1, ps_list **list2)
{
	int	moves;

	moves = 0;
	while (moves < down_moves)
	{
		rrb(list1);
		moves++;
	}
	moves = 0;
	while (moves < up_moves)
	{
		ra(list2);
		moves++;
	}
}

/* void total_cost(ps_list *stack)
{
    ps_list *current;
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

/* void	cost_single_node(ps_list *node, int position)//da cambiare completamente
{
	int	median;
	int	n_nodes;
	int	odd;
	
	n_nodes = count_stack(ft_lstfirst_bd(node));
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