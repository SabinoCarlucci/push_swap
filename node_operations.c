/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:28:54 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 19:36:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ft_lstnew_dl(void *content)
{
	t_ps_list	*n_node;

	n_node = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!n_node)
		return (NULL);
	n_node->content = content;
	n_node->prev = NULL;
	n_node->next = NULL;
	n_node->target = NULL;
	n_node->cost_total = 0;
	n_node->up_down = 0;
	return (n_node);
}

void	ft_lstadd_front_dl(t_ps_list **lst, t_ps_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}

void	ft_lstadd_back_dl(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*l_node;

	l_node = *lst;
	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		l_node = ft_lstlast_dl(*lst);
		l_node->next = new;
		new->prev = l_node;
	}
}

t_ps_list	*ft_lstlast_dl(t_ps_list *lst)
{
	t_ps_list	*current;

	current = lst;
	while (current)
	{
		if ((current -> next) == NULL)
			return (current);
		current = current -> next;
	}
	return (current);
}

t_ps_list	*ft_lstfirst_dl(t_ps_list *lst)
{
	t_ps_list	*current;

	current = lst;
	while (current)
	{
		if ((current -> prev) == NULL)
			return (current);
		current = current -> prev;
	}
	return (current);
}

/* void	print(t_ps_list *head)
{
	t_ps_list *ciccio = head;
    while (ciccio != NULL)
	{
		if (ciccio->content != NULL)
			printf("%d\n", *((int *)(ciccio->content)));
		else
			printf("Nodo vuoto\n");
		ciccio = ciccio->next;
	}
	printf("\n");
} */
/* int main(void) //per reverse_rotate
{
    // Creazione di alcuni nodi di esempio
	int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    // Creazione di una lista vuota
    t_ps_list *head_a = NULL;
    //t_ps_list *head_b = NULL;

    // Aggiunta dei nodi alla lista a
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data3));
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data2));
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data1));

	// Stampa il contenuto dei nodi nella lista
	printf("LISTA A\n");
	print(head_a);

    // rotate
	reverse_rotate(&head_a);

	printf("dopo reverse_rotate\n");
	printf("LISTA A\n");
	print(head_a);
	
    return 0;
} */

/*
int main(void) //per swap
{
    // Creazione di alcuni nodi di esempio
	int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    // Creazione di una lista vuota
    t_ps_list *head_a = NULL;
    //t_ps_list *head_b = NULL;

    // Aggiunta dei nodi alla lista a
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data3));
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data2));
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data1));

	// Stampa il contenuto dei nodi nella lista
	printf("LISTA A\n");
	print(head_a);

    // swap
	swap(&head_a);

	printf("dopo swap\n");
	printf("LISTA A\n");
	print(head_a);
	
    return 0;
}*/

/* int main(void) //per ft_lstadd_front
{
    // Creazione di alcuni nodi di esempio
	int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    // Creazione di una lista vuota
    t_ps_list *head_a = NULL;
    t_ps_list *head_b = NULL;

    // Aggiunta dei nodi alla lista a
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data3));
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data2));
	ft_lstadd_front_dl(&head_a, ft_lstnew_dl(&data1));

	// Stampa il contenuto dei nodi nella lista
	printf("LISTA A\n");
	print(head_a);

	printf("LISTA B\n");
	print(head_b);

    // Aggiunta dei nodi alla lista nella sequenza corretta
    push(&head_a, &head_b);

	printf("dopo primo push\n");
	printf("LISTA A\n");
	print(head_a);

	printf("LISTA B\n");
	print(head_b);
	
    push(&head_a, &head_b); // Aggiunge node2 alla testa, ora node2 è la testa

	printf("dopo secondo push\n");
	printf("LISTA A\n");
	print(head_a);

	printf("LISTA B\n");
	print(head_b);
	
    push(&head_a, &head_b); // Aggiunge node3 alla testa, ora node3 è la testa

    printf("dopo tenzo push\n");
	printf("LISTA A\n");
	print(head_a);

	printf("LISTA B\n");
	print(head_b);
	
    return 0;
} */

/*
int main(void)
{
    int data = 13;
    t_ps_list *new_node = ft_lstnew_dl(&data);

    if (new_node)
        printf("nuovo nodo: %d\n", *((int *)(new_node->content)));
    else
        printf("Fallimento.\n");
    return 0;
}*/