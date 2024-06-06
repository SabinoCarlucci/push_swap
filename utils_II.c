/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:14:30 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/06 18:10:52 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median_get(int count)
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
	while(((current->next) != NULL) && check_order)
	{
		if (*(current ->content) < *((current ->next) ->content))
			check_order = 0;
		current = current->next;
	}
	if (check_order)
		return (1);
	return (0);
}