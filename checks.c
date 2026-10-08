/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:02:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/10/08 10:45:18 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input_repeat(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
	{
		if (check_num(argv[count]))
			return (1);
		count++;
	}
	return (0);
}

int	check_duplicates(t_ps_list	*stack_temp)
{
	int			found;
	t_ps_list	*current;

	found = 0;
	current = stack_temp;
	while (current->next && !found)
	{
		if (*(current->content) == *((current->next)->content))
			found = 1;
		current = current->next;
	}
	return (found);
}

int	check_num(char *arg)
{
	int	negative;
	int	len;

	negative = (arg[0] == '-');
	if (arg[0] == '-' || arg[0] == '+')
		arg++;
	if (!*arg)
		return (error_message());
	while (*arg == '0' && arg[1])
		arg++;
	len = 0;
	while (ft_isdigit(arg[len]))
		len++;
	if (arg[len] || len > 10)
		return (error_message());
	if (len == 10)
		return (check_limits_int(arg, negative));
	return (0);
}

int	check_limits_int(char *digits, int negative)
{
	int		i;
	char	*limit;

	limit = "2147483647";
	if (negative)
		limit = "2147483648";
	i = 0;
	while (digits[i] && digits[i] == limit[i])
		i++;
	if (digits[i] > limit[i])
		return (error_message());
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
