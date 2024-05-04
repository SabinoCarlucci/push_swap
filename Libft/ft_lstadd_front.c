/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:12:09 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/03 12:12:11 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_lstnew.c"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main (void)
{
	t_list	*lst = NULL;
	int	content = 42;
	//t_list *new_node = NULL;

	t_list	*new_node = ft_lstnew(&content);
	ft_lstadd_front(&lst, new_node);

	if (new_node)
        printf("dentro il nodo c'e: %d\n", *((int *)(new_node->content)));
    else
        printf("non ha funzionato\n");
    return 0;
}*/