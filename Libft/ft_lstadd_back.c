/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:42:29 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/22 20:15:47 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include "ft_lstlast.c"
//#include "ft_lstnew.c"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_node;

	l_node = *lst;
	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		l_node = ft_lstlast(*lst);
		l_node->next = new;
	}
}
/*int main()
{
    // Crea una lista vuota
    t_list *myList = NULL;

    // Aggiunge alcuni elementi alla fine della lista
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        t_list *newNode = ft_lstnew(&values[i]);
        ft_lstadd_back(&myList, newNode);
    }

    // Stampa la lista
    t_list *current = myList;
    while (current)
    {
        int *content = (int *)current->content;
        printf("%d ", *content);
        current = current->next;
    }
    printf("\n");

    return 0;
}*/