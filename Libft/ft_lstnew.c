/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:37:56 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/03 11:37:59 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_node;

	n_node = (t_list *)malloc(sizeof(t_list));
	if (!n_node)
		return (NULL);
	n_node->content = content;
	n_node->next = NULL;
	return (n_node);
}
/*
int main(void)
{
    int data = 42;
    t_list *new_node = ft_lstnew(&data);

    if (new_node)
        printf("nuovo nodo: %d\n", *((int *)(new_node->content)));
    else
        printf("Fallimento.\n");
    return 0;
}*/