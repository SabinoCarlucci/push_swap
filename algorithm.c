/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/15 16:19:11 by scarlucc         ###   ########.fr       */
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
		alg_sort_big(stack_a, stack_b);
}

void	alg_sort_three(ps_list	**stack_a, int count)//rinomina con small
{
	if (count == 2)
		sa(stack_a);
	else
	{
		if (*((*stack_a)->content) == 1)
			rra(stack_a);
		else if (*((*stack_a)->content) == 3 && *(((*stack_a)->next)->content) == 2)
			sa(stack_a);
		if (*((*stack_a)->content) == 3)
			ra(stack_a);
		else if (*((*stack_a)->next->content) == 1)
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


void	alg_sort_big(ps_list **stack_a, ps_list	*stack_b)
{
	pb(stack_a, &stack_b);//magari controllo prima per capire se e' meglio pushare altro
	pb(stack_a, &stack_b);
	print_both_stacks(*stack_a, stack_b);//cancella
	printf("\n\n");//cancella
	set_target_cost(*stack_a, stack_b);
	//chiama funzione per fare mossa
}
