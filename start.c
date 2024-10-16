/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:04 by scarlucc          #+#    #+#             */
/*   Updated: 2024/10/16 10:02:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_ps_list	*stack)
{
	t_ps_list	*current;
	int			count;

	current = stack;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_ps_list	*make_lst_from_ints(int argc, char **argv, t_ps_list *stack_a)
{
	int	count;
	int	*node;

	if (check_input_repeat(argv))
		return (NULL);
	count = 0;
	while (count < argc)
	{
		node = (int *)ft_calloc(1, sizeof(int));
		*node = ft_atoi(argv[count]);
		ft_lstadd_back_dl(&stack_a, ft_lstnew_dl(node));
		count++;
	}
	return (stack_a);
}

t_ps_list	*make_lst_from_string(char **argv, t_ps_list *stack_a)
{
	char	**split_out;
	int		count;

	split_out = ft_split(argv[1], ' ');
	count = 0;
	while (split_out[count])
		count++;
	stack_a = make_lst_from_ints(count, split_out, stack_a);
	count = 0;
	while (split_out[count])
		free(split_out[count++]);
	free(split_out);
	return (stack_a);
}

/*
//prova
	sa(&stack_a);
	printf("\nstack A\n");
	print_list(stack_a);
	pb(&stack_a, &stack_b);
	printf("\nstack A\n");
	print_list(stack_a);
	printf("\nstack B\n");
	print_list(stack_b);

	pb(&stack_a, &stack_b);
	printf("\nstack A\n");
	print_list(stack_a);
	printf("\nstack B\n");
	print_list(stack_b);

	sb(&stack_b);
	printf("\nstack B\n");
	print_list(stack_b);

	ss(&stack_a, &stack_b);
	printf("\nstack A\n");double_moves
	print_list(stack_a);
	printf("\nstack B\n");
	print_list(stack_b);

	pa(&stack_b, &stack_a);
	printf("\nstack A\n");
	print_list(stack_a);
	printf("\nstack B\n");
	print_list(stack_b);

//che sucede se svuoti una delle due liste?
//cosa dovrebbe succedere?
	
	//prova
*/

/* //prova
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	printf("\nstack A\n");
	print_stack(stack_a);
	printf("\nstack B\n");
	print_stack(stack_b);

	rra(&stack_a);
	printf("\nstack A\n");
	print_stack(stack_a);

	rrb(&stack_b);
	printf("\nstack B\n");
	print_stack(stack_b);

	rrr(&stack_a, &stack_b);
	printf("\nstack A\n");
	print_stack(stack_a);
	printf("\nstack B\n");
	print_stack(stack_b);
	//prova */