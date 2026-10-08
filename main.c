/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:02:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/10/08 10:25:35 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = make_lst_from_string(argv, stack_a);
	else
		stack_a = make_lst_from_ints((argc - 1), (argv + 1), stack_a);
	if (!stack_a)
		return (1);
	if (indexing(stack_a))
	{
		free_list(stack_a);
		return (error_message());
	}
	if (!already_ordered(stack_a))
		alg_start(&stack_a);
	free_list(stack_a);
	return (0);
}
