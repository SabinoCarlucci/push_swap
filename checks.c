/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:14:55 by scarlucc          #+#    #+#             */
/*   Updated: 2024/04/29 19:26:06 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(ps_list *stack)//commenta prima di consegnare, anche in .h
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
}

int	check_input(char **argv, int count)
{
	int	incr;
	int	n;
	
	while (argv[count])
	{
		check_num(argv[count]);
		incr = 1;
		while (argv[count + incr])
		{
			if (ft_strlen(argv[count]) > ft_strlen(argv[count + incr]))
				n = ft_strlen(argv[count]);
			else
				n = ft_strlen(argv[count + incr]);
			if(!(ft_strncmp(argv[count], argv[count + incr], n)))
				error_message();
			incr++;
		}
		count++;
	}
	return (count);
}

void	check_num(char *arg)
{
	int		count;
	
	count = 0;
	if (arg[0] == '-' || arg[0] == '+')
		count++;
	while (arg[count])
	{
		if (!(ft_isdigit(arg[count])) || count > (10 + (arg[0] == '-' || arg[0] == '+')))
			error_message();
		count++;
	}
	if (count == (10 + (arg[0] == '-' || arg[0] == '+')))
		check_limits_int(arg);
}

void	check_limits_int(char *arg)
{
	int		plus;
	int		minus;
	char	*compare;
	
	plus = 1;
	minus = 0;
	if (arg[0] == '-' || arg[0] == '+')
		minus = plus;
	compare = (char *)ft_calloc(10 + minus + plus, sizeof(char));
	if (arg[0] == '-')
		compare = "-2147483648\0";
	else if (arg[0] == '+')
		compare = "+2147483647\0";
	else
		compare = "2147483647\0";
	while (arg[minus])//confronta ogni carattere di arg con compare, se > allora return NULL
	{
		if (arg[minus] > compare[minus])
			error_message();
		minus++;
	}
}

void	error_message(void)
{
	char	*string;
	
	string = (char *)ft_calloc(7, sizeof(char));
	string = "Error\n\0";
	ft_putstr_fd(string, 2);
	exit(1);
}
