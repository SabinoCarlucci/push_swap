/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/22 11:08:47 by scarlucc         ###   ########.fr       */
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

void	push_chunks(t_ps_list	**stack_a, t_ps_list	**stack_b, int count)
{
	int	step;
	int	left_in_a;
	int	n;
	int	pushed;
	//int	binary;
	//int a = 1;//togli
	int infinito = 0;//togli

	//binary = 0;
	pushed = 0;
	step = make_chunks(count);
	n = 1;//cambia nome se riesci a scrivere condizione grssa su due righe
	if ((count % step) > 3 || (count % step) == 0 || count == 5)//queste 4 righe possono diventare 3 invertendo
		left_in_a = 3;
	else
		left_in_a = count % step;
	while (count > left_in_a)
	{			
		/* printf("n = %d\n", n);
		printf("step = %d\n", step);
		printf("content = %d\n", *((*stack_a)->content));
		printf("lista B = %d\n", count_stack(*stack_b));
		printf("count = %d\n", count);
		printf("left in a = %d\n", left_in_a);
		printf("iterazioni = %d\n\n", infinito); */
		if (*((ft_lstlast_dl(*stack_a))->content) >= n && *((ft_lstlast_dl(*stack_a))->content) < (n + step))
			rra(stack_a);
		if (*((*stack_a)->content) >= n && *((*stack_a)->content) < (n + step))//se nodo e' nello stack, pushalo in b, altrimenti rotate
		{
			pb(stack_a, stack_b);
			//printf("================================");
			count--;
			pushed++;
			/* if (binary == 1)
				rb(stack_b); */
			if (pushed == step)
			{
				n += step;
				step = make_chunks(count);
				pushed = 0;
				/* if (binary == 0)
					binary = 1;
				else
					binary = 0; */
				infinito++;//togli
				/* if (n > 100)
					exit(1); */
			}
		}
		else
		{
			//printf("(%d)", a++);//togli//500 blocca qui
			ra(stack_a);
		}
	}
}

void	push_chunks2(t_ps_list	**stack_a, t_ps_list	**stack_b, int count)//per 5 numeri conviene quello vecchio
{
	int	n = 1;
	int	step = count / 3;
	int	pushed = 0;
	//int a = 1;
	while (pushed < (count - 3) && !already_ordered(*stack_a))
	{
		
		/* printf("n = %d\n", n);
		printf("step = %d\n", step);
		printf("content = %d\n", *((*stack_a)->content));
		printf("count B = %d\n", count_stack(*stack_b));
		printf("count A = %d\n", count_stack(*stack_a));
		printf("count = %d\n", count);
		printf("pushed = %d\n", pushed); */
		/* if (*((ft_lstlast_dl(*stack_a))->content) >= n && *((ft_lstlast_dl(*stack_a))->content) < (n + step + step))
			rra(stack_a); */
		if (*((*stack_a)->content) >= n && (*((*stack_a)->content) < (n + step + step)) && *((*stack_a)->content) <= (count - 3))
		{
			pb(stack_a, stack_b);
			//count--;
			pushed++;
		}
		else
		{
			//printf("(%d)", a++);//togli//100 blocca qui
			ra(stack_a);
		}
			
		if (*stack_b && (*stack_b)->content && *((*stack_b)->content) >= n && *((*stack_b)->content) < (n + step))
			rb(stack_b);//come evito rb inutili???
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
	if (count <= 500 && count >= 400)//metti caso 500+
		size_chunk = count / 10;
	else if (count <= 400 && count >= 200)
		size_chunk = count / 8;
	else if (count <= 200 && count > 5)
		size_chunk = count / 6;
	if ((count - size_chunk) > 0 && (count - size_chunk) < 4)//mettere dentro ciclo?
		return (size_chunk);
		/*
	while (size_chunk <= 20 && (count / size_chunk) >= size_chunk)
		size_chunk++;*/
	return (size_chunk); 
}

/*int	size_chunks(int	count)
{
	//minimo 3 elementi per chunk
	//massimo 12 chunk
	int	size_chunk;
	
	if (count <=7)
		
	return (size_chunk);
} */

void	make_move(t_ps_list **stack_start, t_ps_list **stack_targ)
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
		bring_to_top(cheapest, stack_start, stack_targ);
	pa(stack_start, stack_targ);
}

void	last_fix(t_ps_list **stack_a, int count)
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
			rra(stack_a);
	}
	else
	{
		while ((consecutives--) > 0)
			ra(stack_a);
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