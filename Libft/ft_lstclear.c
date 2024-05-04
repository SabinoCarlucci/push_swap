/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:17:34 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/06 15:17:38 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_lstadd_back.c"
//#include "ft_lstlast.c"
//#include "ft_lstnew.c"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (lst && del)
	{
		next_node = NULL;
		while (*lst)
		{
			next_node = (*lst)-> next;
			del((*lst)-> content);
			free(*lst);
			*lst = next_node;
		}
		lst = NULL;
	}
}
/*void delete_int(void *data)
{
    free(data);
}

int main()
{
    t_list *myList = NULL;

    for (int i = 1; i <= 5; i++)
    {
        int *value = (int *)malloc(sizeof(int));
        *value = i;
        t_list *newNode = ft_lstnew(value);
        ft_lstadd_back(&myList, newNode);
    }

    printf("Lista prima della cancellazione:\n");
    t_list *current = myList;
    while (current)
    {
        int *content = (int *)current->content;
        printf("%d ", *content);
        current = current->next;
    }
    printf("\n");

    ft_lstclear(&myList, delete_int);

    printf("Lista dopo la cancellazione:\n");
    if (myList == NULL)
        printf("La lista è vuota.\n");
    return 0;
}*/
