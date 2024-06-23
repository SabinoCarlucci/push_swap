/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:14:55 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 17:33:45 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_input_repeat(char **argv)
{
   int count;
   int incr;


   count = 0;
   while (argv[count])
   {
       if(check_num(argv[count]))
           return (1);
       incr = 1;
       while (argv[count + incr])
       {
           if(check_duplicates(argv[count], argv[count + incr]) == 0)
               return(error_message());
           incr++;
       }
       count++;
   }
   return (0);
}


int check_duplicates(const char *input, const char *input_next)
{
   int compare;


   if (*input == '+' || *input == '-')
       input++;
   if (*input_next == '+' || *input_next == '-')
       input_next++;
   if (ft_strlen(input) > ft_strlen(input_next))
       compare = ft_strlen(input);
   else
       compare = ft_strlen(input_next);
   return((ft_strncmp(input, input_next, compare)));
}

int	check_num(char *arg)//controlla se ci metti + o - in mezzo ai numeri
{
	int		count;
	
	count = 0;
	if (arg[0] == '-' || arg[0] == '+')
		count++;
	while (arg[count])
	{
		if (!(ft_isdigit(arg[count])) || count > (10 + (arg[0] == '-' || arg[0] == '+')))
			return(error_message());
		count++;
	}
	if (count == (10 + (arg[0] == '-' || arg[0] == '+')))
		return(check_limits_int(arg));
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
			return(error_message());
		minus++;
	}
	return (0);
}

int	already_ordered(t_ps_list *stack)//0 se non ordinata, 1 se ordinata
{
	int		check_order;
	t_ps_list	*current;

	check_order = 1;
	current = stack;
	while(((current->next) != NULL) && check_order)
	{
		if (*(current->content) > *((current->next)->content))
			check_order = 0;
		current = current->next;
	}
	if (check_order)
		return (1);
	return (0);//direttamente return (check order)
}

int	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	print_list(t_ps_list *stack)//commenta prima di consegnare, anche in .h
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

void	print_stack(t_ps_list *stack)//commenta prima di consegnare, anche in .h
{
	//stack = ft_lstfirst_dl(stack);
	while (stack)
	{
		printf("%i \n", *(stack->content));
		stack = stack->next;
	}
}

void	print_both_stacks(t_ps_list *stack_a, t_ps_list *stack_b)//commenta prima di consegnare, anche in .h
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
}

t_ps_list	*make_lst_from_array(int	*array, int size, t_ps_list *stack_a)//non la uso, cancellare prima di consegnare, anche da .h
{
	int *node;
	int	count;

	count = 0;
	while (count < size)
	{
		node = (int *)ft_calloc(1, sizeof(int));
		*node = array[count];
		ft_lstadd_back_dl(&stack_a, ft_lstnew_dl(node));
		count++;
	}
	//free(node);//non sono sicuro di doverlo togliere, ma se va tolto, allora va gestito nella lista
	return (stack_a);
}