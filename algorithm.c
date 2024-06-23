/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:44:05 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/22 18:15:59 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_start(t_ps_list	**stack_a, t_moves **stack_moves)
{
	int	count;
	t_ps_list	**stack_b;

	stack_b = (t_ps_list **)malloc(sizeof(t_ps_list *));
    if (stack_b)
		*stack_b = NULL;
	count = count_stack(*stack_a);
	if (count == 2)
		sa(stack_a, stack_moves);
	else if (count < 4)
		alg_sort_one_to_three(stack_a, stack_b, stack_moves);
	/* else if (count == 5)//aggiungi caso di 4 numeri
		alg_sort_five(stack_a, stack_b, 3); */
	else
		alg_sort_big(stack_a, stack_b, count, stack_moves);
	free(stack_b);
}

void	alg_sort_one_to_three(t_ps_list	**stack_a, t_ps_list	**stack_b, t_moves **stack_moves )
{
	if ((*((*stack_a)->content) < *((*stack_a)->next->content))
		&& (*((*stack_a)->content) < *((*stack_a)->next->next->content)))
		rra(stack_a, stack_moves);
	else if ((*((*stack_a)->content) > *((*stack_a)->next->content))
		&& (*((*stack_a)->next->content)
			> *((*stack_a)->next->next->content)))
	{
		if ((count_stack(*stack_b) > 1) && (*(*stack_b)->content < *(*stack_b)->next->content))
			ss(stack_a, stack_b, stack_moves);
		else
			sa(stack_a, stack_moves);
	}
	if ((*((*stack_a)->content) > *((*stack_a)->next->content))
		&& (*((*stack_a)->content) > *((*stack_a)->next->next->content)))
		ra(stack_a, stack_moves);
	else if ((*((*stack_a)->next->content) < *((*stack_a)->content))
		&& (*((*stack_a)->next->content)
			< *((*stack_a)->next->next->content)))
	{
		if ((count_stack(*stack_b) > 1) && (*(*stack_b)->content < *(*stack_b)->next->content))
				ss(stack_a, stack_b, stack_moves);
		else
			sa(stack_a, stack_moves);
	}
	else
		rra(stack_a, stack_moves);
}

void	alg_sort_big(t_ps_list **stack_a, t_ps_list	**stack_b, int count, t_moves **stack_moves)
{	
	int stack_size_st;
	int stack_size_tar;

	//push_chunks(stack_a, stack_b, count);
	push_chunks2(stack_a, stack_b, count, stack_moves);
	stack_size_st = count_stack(*stack_b);
	stack_size_tar = count_stack(*stack_a);
	if (!already_ordered(*stack_a) && stack_size_tar > 1)
	{
		if (stack_size_tar == 2)
			sa(stack_a, stack_moves);
		else
			alg_sort_one_to_three(stack_a, stack_b, stack_moves);
	}
	//int a = 0;
    while (*stack_b && (*stack_b)->content)//aggiunto * davanti primo stack_b
	{
		//printf("(%d %d)", *(*stack_b)->content, a++);
		set_target_cost(*stack_b, *stack_a, stack_size_st--, stack_size_tar++);
    	make_move(stack_b, stack_a, stack_moves);
	}
	//printf("hello");
	if (!already_ordered(*stack_a))//0 se non ordinata, 1 se ordinata
		last_fix(stack_a, count, stack_moves);
}

/* void	sort_five_start(t_ps_list **stack_a, t_ps_list **stack_b, int median)//non funziona piu!!!!
{
	if (*(ft_lstlast_dl(*stack_a))->content == 1)
		rra(stack_a);
	if (*((*stack_a)->content) < median)
	{
		if (*((*stack_a)->content) > *((*stack_a)->next->content))
			sa(stack_a);
		pb(stack_a, stack_b);
	}	
	else
	{
		if (*((*stack_a)->content) > *((*stack_a)->next->content))
		{
			if (*((*stack_a)->next->content) > median)
			{
				if (*stack_b && !reverse_ordered(*stack_b))//provocava segfault con numeri 5 4 3 1 2 perche' stack_b era vuota, ora fa 9 mosse
					ss(stack_a, stack_b);
				else if (*(ft_lstlast_dl(*stack_a)->content) == 2)//con 5 4 3 1 2 fa 9 mosse invece di 8, ancora non capisco perche'
				{
					rra(stack_a);
					if (*(ft_lstlast_dl(*stack_a)->content) == 1)
					{
						rra (stack_a);
						pb(stack_a, stack_b);
					}
					pb(stack_a, stack_b);
				}
				else
					sa(stack_a);
			}
		}
		ra(stack_a);//metti altre condizioni tipo se due numeri sono consecutivi
	}
}

void	alg_sort_five(t_ps_list	**stack_a, t_ps_list	*stack_b, int	median)//caso di 9 mosse e caso di 10!!! e accorcia funzione
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
	if (!already_ordered(*stack_a))
		sa(stack_a);
	while (stack_b)
		pa(&stack_b, stack_a);
} */
