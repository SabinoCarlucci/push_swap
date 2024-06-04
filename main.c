/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:04 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/31 17:58:13 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ps_list	*make_lst_from_ints(int argc, char **argv, ps_list *stack_a)
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
		ft_lstadd_back_bd(&stack_a, ft_lstnew_bd(node));
		count++;
	}
	return (stack_a);
}

ps_list	*make_lst_from_string(char **argv, ps_list *stack_a)
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

int	main(int argc, char **argv)
{
	ps_list	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = make_lst_from_string(argv, stack_a);
	else
		stack_a = make_lst_from_ints((argc - 1), (argv + 1), stack_a);
	if (!stack_a)
		exit(1);
	if (!already_ordered(stack_a))
	{
		printf("algoritmo, vieni a me!\n");//chiama algoritmo
		stack_temp(stack_a);
		alg_start(&stack_a);
	}
	printf("\nstack_A fine main\n");//togli prima di consegna
	print_stack(stack_a);//togli prima di consegna
	free_list(stack_a);
	stack_a = NULL;
	return (0);
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
	printf("\nstack A\n");
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