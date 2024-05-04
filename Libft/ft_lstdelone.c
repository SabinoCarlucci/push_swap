/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:53:33 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/06 11:53:36 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_lstnew.c"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst -> content);
	free(lst);
}
/*void delete_int(void *data)
{
    free(data);
}

int main()
{
    int *value = (int *)malloc(sizeof(int));
    *value = 42;
    t_list *node = ft_lstnew(value);

    printf("Valore prima della cancellazione: %d\n", *(int *)(node->content));

    ft_lstdelone(node, delete_int);

    if (node == NULL)
        printf("Nodo cancellato con successo.\n");
    else
        printf("Errore: il nodo non è stato cancellato correttamente.\n");
    return 0;
}*/
