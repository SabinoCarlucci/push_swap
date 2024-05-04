/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:04 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/03 11:16:46 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ps_list *make_lst_from_ints(int argc, char **argv, ps_list *stack_a)
{
	int	*array;
	int	count;
	int number;
	int *node;

	printf("interi separati\n");//togli prima di consegnare
	count = check_input(argv, 1);
	array = (int *)ft_calloc(count, sizeof(int));
	count = 0;
	while (count <= (argc - 2))
	{
		number = ft_atoi(argv[count + 1]);
		array[count] = number;
		node = (int *)ft_calloc(1, sizeof(int));
		*node = number;
		ft_lstadd_back_bd(&stack_a, ft_lstnew_bd(node));
		count++;
	}	
	return (stack_a);
}

ps_list *make_lst_from_string(char **argv, ps_list *stack_a)
{
	char	**split_out;
	int		count;
	int		*array;
	int		*node;
	int 	number;

	printf("stringa di interi\n");//togli prima di consegnare
	split_out = ft_split(argv[1], ' ');
	if (!split_out[1])//se non ci sono spazi, il numero e' uno, e esci
		error_message();
	count = check_input(split_out, 0);
	array = (int *)ft_calloc(count, sizeof(int));//forse count + 1, forse no perche' sono numeri
	count = 0;
	number = 0;
	while (split_out[count])
	{
		array[count] = ft_atoi(split_out[count]);
		node = (int *)ft_calloc(1, sizeof(int));
		number = array[count];
		*node = number;
		ft_lstadd_back_bd(&stack_a, ft_lstnew_bd(node));
		count++;
	}
	return (stack_a);
}

int main(int argc, char **argv)//questa funzione diventa push_swap
{
	ps_list *stack_a;
	
	stack_a = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		stack_a = make_lst_from_string(argv, stack_a);
		if (!stack_a)//a che serve?
			return (0);
	} else
		stack_a = make_lst_from_ints(argc, argv, stack_a);
	print_list(stack_a);//togli prima di consegna
	return (0);
}
