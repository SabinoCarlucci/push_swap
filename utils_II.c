/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/19 19:10:37 by scarlucc         ###   ########.fr       */
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

void	set_target_cost(ps_list	*stack_st, ps_list	*stack_target, int stack_size_st, int stack_size_tar)//forse cambiare di nuovo da int a void
{
	ps_list	*current;
	int		cost_up;
	//int a = 0;//togli

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
	//printf("(%d)", a++);//togli
	while (current)//mettere in altra funzione e richiamare due volte
	{
		find_target(current, stack_target);
		current->cost_up = cost_up;
		current->cost_down = (stack_size_st - cost_up);
		cost_up++;
		current = current->next;
	}
	/* if (stack_size_st == 0)
		return (1); */
	total_cost(stack_st);
	//return (0);
}

void	push_chunks(ps_list	**stack_a, ps_list	**stack_b, int count)
{
	int	max;
	int	step;
	int	left_in_a;
	int	n;

	//step = size_chunks(count);
	step = make_chunks(count);
	n = 1;//cambia nome se riesci a scrivere condizione grssa su due righe
	if ((count % step) > 3)
		left_in_a = 3;
	else
		left_in_a = count % step;
	max = count - left_in_a;
	
	//int a = 0;//togli
	
	while (count > left_in_a)//mettere altra condizione per evitare loop infinito?
	{			
		if (*((*stack_a)->content) >= n && *((*stack_a)->content) < (n + step))//se nodo e' nello stack, pushalo in b, altrimenti rotate
		{
			pb(stack_a, stack_b);
			count--;
			/* if ((max - (n + step + step)) < step)//problema qui
				n += (max - (n + step + step)); */
			if ((count - left_in_a) % step == 0)
				n += step;
			/* if ((count - (max % step)) % step == 0)//con 7 numeri da problemi
				n += step; */
			/* if ((max - (n + step)) < step)
				n += (max - (n + step + step));//la differenza tra il massimo e il numero esatto 
			if ((count - 3 - (max % step)) % step == 0)
				n += step; */
		}//prima di questo metti else if numero e' in fondo a stack, fai rra e poi push
		else /* (*((*stack_a)->content) > max) */
		{
			//printf("(%d)", a++);//togli
			ra(stack_a);
		}
	}
}

int	make_chunks(int	count)
{
	int	size_chunk;

	size_chunk = 3;
	while (size_chunk <= 20 && (count / size_chunk) >= size_chunk)
		size_chunk++;
	return (size_chunk);
}

/* int	size_chunks(int	count)
{
	//minimo 3 elementi per chunk
	//massimo 12 chunk
	int	size_chunk;
	
	if (count <=7)
		size_chunk = 4;
	else if (count <= 100)
		size_chunk = 12;
	else
		size_chunk = 20;
	return (size_chunk);
} */

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

void	last_fix(ps_list **stack_a, int count)
{
	ps_list	*current;
	int		consecutives;
	//int a = 0;
	
	consecutives = 1;
	current = *stack_a;
	while (*(current)->content == (*(current)->next->content - 1))
	{
		consecutives++;
		current = current->next;
	}
	if (consecutives > (count - consecutives))
	{
		while (consecutives-- > 0)
			rra(stack_a);
	}
	else
	{
		while (consecutives-- > 0)
		{
			//printf("(%d)", a++);//togli
			ra(stack_a);
		}
			
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