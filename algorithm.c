/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/18 11:38:48 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_start(ps_list	**stack_a)
{
	int	count;
	ps_list	*stack_b;

	stack_b = NULL;
	count = count_stack(*stack_a);
	if (count < 4)
		alg_sort_three(stack_a, count);
	else if (count == 5)//aggiungi caso di 4 numeri
		alg_sort_five(stack_a, stack_b, 3);
	else
		alg_sort_big(stack_a, &stack_b, count);
}

void	alg_sort_three(ps_list	**stack_a, int count)//rinomina con small
{
	if (count == 2)
		sa(stack_a);
	else
	{
		if ((*((*stack_a)->content) < *((*stack_a)->next->content))
			&& (*((*stack_a)->content) < *((*stack_a)->next->next->content)))
			rra(stack_a);
		else if ((*((*stack_a)->content) > *((*stack_a)->next->content))
			&& (*((*stack_a)->next->content)
				> *((*stack_a)->next->next->content)))
			sa(stack_a);
		if ((*((*stack_a)->content) > *((*stack_a)->next->content))
			&& (*((*stack_a)->content) > *((*stack_a)->next->next->content)))
			ra(stack_a);
		else if ((*((*stack_a)->next->content) < *((*stack_a)->content))
			&& (*((*stack_a)->next->content)
				< *((*stack_a)->next->next->content)))
			sa(stack_a);
		else
			rra(stack_a);
	}//qui chiama algoritmo per 5
}

void	sort_five_start(ps_list **stack_a, ps_list **stack_b, int median)
{
	if (*(ft_lstlast_bd(*stack_a))->content == 1)
		rra(stack_a);
	if (*((*stack_a)->content) < median)
		pb(stack_a, stack_b);//altro if che forse fa swap
	else
	{
		if (*((*stack_a)->content) > *((*stack_a)->next->content))
		{
			if (*((*stack_a)->next->content) > median)
			{
				if (*stack_b && !reverse_ordered(*stack_b))//provocava segfault con numeri 5 4 3 1 2 perche' stack_b era vuota, ora fa 9 mosse
					ss(stack_a, stack_b);
				else if (*(ft_lstlast_bd(*stack_a)->content) == 2)//con 5 4 3 1 2 fa 9 mosse invece di 8, ancora non capisco perche'
				{
					rra(stack_a);
					pb(stack_a, stack_b);
				}
				else
					sa(stack_a);
			}
		}
		ra(stack_a);//metti altre condizioni tipo se due numeri sono consecutivi
	}
}

void	alg_sort_five(ps_list	**stack_a, ps_list	*stack_b, int	median)//caso di 9 mosse e caso di 10!!! e accorcia funzione
{
	while (count_stack(stack_b) < 2)
		sort_five_start(stack_a, &stack_b, median);
	if (*((*stack_a)->content) == 5)
		ra(stack_a);	
	else if (*((*stack_a)->content) == 4)
	{
		if (*((*stack_a)->next->content) == 5)
			rra(stack_a);
		else
			if (!reverse_ordered(stack_b))
				ss(stack_a, &stack_b);
			else
				sa(stack_a);
	}
	else if (*((*stack_a)->next->content) == 5)
	{
		if (!reverse_ordered(stack_b))
			ss(stack_a, &stack_b);
		else
			sa(stack_a);
		ra(stack_a);
	}
	while (stack_b)
		pa(&stack_b, stack_a);
}


void	alg_sort_big(ps_list **stack_a, ps_list	**stack_b, int count)
{
    //print_both_stacks(*stack_a, *stack_b);
    
	//mettere puntatori singoli
	
    push_chunks(stack_a, stack_b, count);
    
    /* printf("After push_chunks\n");
    print_both_stacks(*stack_a, *stack_b); */

	if (!already_ordered(*stack_a))
		alg_sort_three(stack_a, 3);
	
	/* printf("After alg_sort_three\n");
    print_both_stacks(*stack_a, *stack_b); */

	int stack_size_st = count_stack(*stack_b);
	int stack_size_tar = count_stack(*stack_a);

    while (stack_b)
	{
		if (!set_target_cost(*stack_b, *stack_a, stack_size_st--, stack_size_tar++))
    		make_move(stack_b, stack_a);
		/* printf("dentro ciclo\n");
		print_both_stacks(*stack_a, *stack_b); */
		/* while ((*stack_a)->prev != NULL)//queste 4 righe forse vanno altrove, forse non servono piu'
			*stack_a = (*stack_a)->prev;
		while ((*stack_b)->prev != NULL)
			*stack_b = (*stack_b)->prev; */
	}
	printf("hello");
	if (!already_ordered(*stack_a))//0 se non ordinata, 1 se ordinata
		last_fix(stack_a, count);
	
    /* printf("After ciclo\n");
    print_both_stacks(*stack_a, *stack_b); */

	
}
