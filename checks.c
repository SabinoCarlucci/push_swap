/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:14:55 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 22:28:01 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input_repeat(char **argv)
{
	int	count;
	int	incr;

	count = 0;
	while (argv[count])
	{
		if (check_num(argv[count]))
			return (1);
		incr = 1;
		while (argv[count + incr])
		{
			if (check_duplicates(argv[count], argv[count + incr]) == 0)
				return (error_message());
			incr++;
		}
		count++;
	}
	return (0);
}

int	check_duplicates(const char *input, const char *input_next)
{
	int	compare;

	if (*input == '+')
		input++;
	if (*input_next == '+')
		input_next++;
	if (ft_strlen(input) > ft_strlen(input_next))
		compare = ft_strlen(input);
	else
		compare = ft_strlen(input_next);
	return ((ft_strncmp(input, input_next, compare)));
}

int	check_num(char *arg)
{
	int		count;

	count = 0;
	if ((arg[0] == '-' && arg[1]) || (arg[0] == '+' && arg[1]))
		count++;
	while (arg[count])
	{
		if (!(ft_isdigit(arg[count]))
			|| count > (10 + (arg[0] == '-' || arg[0] == '+')))
			return (error_message());
		count++;
	}
	if (count == (10 + (arg[0] == '-' || arg[0] == '+')))
		return (check_limits_int(arg));
	return (0);
}

int	check_limits_int(char *arg)
{
	int		plus;
	int		minus;
	char	*compare;

	plus = 1;
	minus = 0;
	if (arg[0] == '-' || arg[0] == '+')
		minus = plus;
	if (arg[0] == '-')
		compare = "-2147483648\0";
	else if (arg[0] == '+')
		compare = "+2147483647\0";
	else
		compare = "2147483647\0";
	while (arg[minus])
	{
		if (arg[minus] > compare[minus])
			return (error_message());
		minus++;
	}
	return (0);
}

int	already_ordered(t_ps_list *stack)
{
	int			check_order;
	t_ps_list	*current;

	check_order = 1;
	current = stack;
	while (((current->next) != NULL) && check_order)
	{
		if (*(current->content) > *((current->next)->content))
			check_order = 0;
		current = current->next;
	}
	if (check_order)
		return (1);
	return (0);
}

/* void	print_list(t_ps_list *stack)
{
	while (stack)
	{
		printf("content:%i \n", *(stack->content));
		if (stack->prev)
			printf("prev:%i \n", *(stack->prev->content));
		else
			printf("prev: NULL \n");
		if (stack->next)
			printf("next:%i \n", *(stack->next->content));
		else
			printf("next: NULL \n");
		printf("\n");
		stack = stack->next;
	}
} */

/* void	print_stack(t_ps_list *stack)
{
	//stack = ft_lstfirst_dl(stack);
	while (stack)
	{
		printf("%i \n", *(stack->content));
		stack = stack->next;
	}
} */

/* void	print_both_stacks(t_ps_list *stack_a, t_ps_list *stack_b)
{
	printf("AAA     BBB\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%i", *(stack_a->content));
			stack_a = stack_a->next;
		}
		else
			printf("   ");
		if (stack_b)
		{
			printf("     %i", *(stack_b->content));
			stack_b = stack_b->next;
		}
		printf("\n");
	}
} */
