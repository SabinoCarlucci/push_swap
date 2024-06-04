/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:16:08 by scarlucc          #+#    #+#             */
/*   Updated: 2024/05/31 19:37:04 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct bd_list
{
	int			*content;
	struct bd_list	*prev;
	struct bd_list	*next;
}					ps_list;

ps_list	*ft_lstnew_bd(void *content);
void	ft_lstadd_front_bd(ps_list **lst, ps_list *new);
void	ft_lstadd_back_bd(ps_list **lst, ps_list *new);
ps_list	*ft_lstlast_bd(ps_list *lst);
ps_list	*ft_lstfirst_bd(ps_list *lst);
//moves_basic
void	swap(ps_list **head);
void	push(ps_list **from, ps_list **to);
void	rotate(ps_list **head);
void	reverse_rotate(ps_list **head);
//moves_advanced
void	sa(ps_list **stack_a);
void	sb(ps_list **stack_b);
void	ss(ps_list **stack_a, ps_list **stack_b);
void	pa(ps_list **stack_b, ps_list **stack_a);
void	pb(ps_list **stack_a, ps_list **stack_b);
void	ra(ps_list **stack_a);
void	rb(ps_list **stack_b);
void	rr(ps_list **stack_a, ps_list **stack_b);
void	rra(ps_list **stack_a);
void	rrb(ps_list **stack_b);
void	rrr(ps_list **stack_a, ps_list **stack_b);
//checks
void print_list(ps_list *stack_a);//cancella prima di consegnare
void	print_stack(ps_list *stack);//cancella prima di consegnare
void	print_both_stacks(ps_list *stack_a, ps_list *stack_b);//cancella prima di consegnare
int	check_input_repeat(char **argv);
int	check_num(char *arg);
int	check_limits_int(char *arg);
ps_list	*make_lst_from_array(int	*array, int size, ps_list *stack_a);
int	error_message();
//utils
void free_list(ps_list *stack);
int	already_ordered(ps_list *stack);
void    stack_temp(ps_list  *stack_a);
void	bubble_sort(ps_list  *stack_temp);
void	index_stack_a(ps_list  *stack_a, ps_list  *stack_temp);
int	count_stack(ps_list	*stack);
//algorithm
void	alg_start(ps_list	**stack_a);
void	alg_sort_small(ps_list	**stack_a, int	count);
void	alg_sort_medium(ps_list	**stack_a, int	count);

#endif