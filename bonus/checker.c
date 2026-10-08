/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:57:33 by scarlucc          #+#    #+#             */
/*   Updated: 2024/10/16 19:10:51 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_moves_c(char *move, int *stop,
		t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		*stop = 1;
}

void	check_moves_b(char *move, int *stop,
		t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else
		check_moves_c(move, stop, stack_a, stack_b);
}

void	check_moves(t_ps_list **stack_a, t_ps_list **stack_b)
{
	char	*move;
	int		zero;
	int		*stop;

	zero = 0;
	stop = &zero;
	while (*stop == 0)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		check_moves_b(move, stop, stack_a, stack_b);
		free(move);
	}
	if (*stop == 1)
		error_message();
	else if (*stack_b == NULL && already_ordered(*stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
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
	check_moves(&stack_a, &stack_b);
	free_list(stack_a);
	stack_a = NULL;
	free_list(stack_b);
	stack_b = NULL;
	return (0);
}
