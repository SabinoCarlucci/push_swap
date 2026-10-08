/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/10/08 09:44:15 by scarlucc         ###   ########.fr       */
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
	if (!split_out)
		return (NULL);
	count = 0;
	while (split_out[count])
		count++;
	if (count == 0)
		error_message();
	else
		stack_a = make_lst_from_ints(count, split_out, stack_a);
	count = 0;
	while (split_out[count])
		free(split_out[count++]);
	free(split_out);
	return (stack_a);
}
