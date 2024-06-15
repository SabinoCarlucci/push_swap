/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:28:54 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/14 17:44:34 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ps_list	*ft_lstnew_bd(void *content)
{
	ps_list	*n_node;

	n_node = (ps_list *)malloc(sizeof(ps_list));
	//n_node = (ps_list *)ft_calloc(1, sizeof(ps_list));
	if (!n_node)
		return (NULL);
	n_node->content = content;
	n_node->prev = NULL;
	n_node->next = NULL;
	n_node->target = NULL;
	n_node->cost = 0;
	n_node->median = 0;
	return (n_node);
}

void	ft_lstadd_front_bd(ps_list **lst, ps_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}

void	ft_lstadd_back_bd(ps_list **lst, ps_list *new)
{
	ps_list	*l_node;

	l_node = *lst;
	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		l_node = ft_lstlast_bd(*lst);
		l_node->next = new;
		new->prev = l_node;
	}
}

ps_list	*ft_lstlast_bd(ps_list *lst)
{
	ps_list	*current;

	current = lst;
	while (current)
	{
		if ((current -> next) == NULL)
			return (current);
		current = current -> next;
	}
	return (current);
}

ps_list	*ft_lstfirst_bd(ps_list *lst)
{
	ps_list	*current;

	current = lst;
	while (current)
	{
		if ((current -> prev) == NULL)
			return (current);
		current = current -> prev;
	}
	return (current);
}

/* void	print(ps_list *head)
{
	ps_list *ciccio = head;
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
    ps_list *head_a = NULL;
    //ps_list *head_b = NULL;

    // Aggiunta dei nodi alla lista a
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data3));
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data2));
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data1));

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
    ps_list *head_a = NULL;
    //ps_list *head_b = NULL;

    // Aggiunta dei nodi alla lista a
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data3));
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data2));
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data1));

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
    ps_list *head_a = NULL;
    ps_list *head_b = NULL;

    // Aggiunta dei nodi alla lista a
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data3));
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data2));
	ft_lstadd_front_bd(&head_a, ft_lstnew_bd(&data1));

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
    ps_list *new_node = ft_lstnew_bd(&data);

    if (new_node)
        printf("nuovo nodo: %d\n", *((int *)(new_node->content)));
    else
        printf("Fallimento.\n");
    return 0;
}*/