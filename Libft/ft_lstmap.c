/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:53:36 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/07 16:53:38 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_lstnew.c"
//#include "ft_lstclear.c"
//#include "ft_lstadd_back.c"
//#include "ft_lstlast.c"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_first;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_node = NULL;
	new_first = NULL;
	while (lst)
	{
		temp = f(lst-> content);
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			del(temp);
			ft_lstclear(&new_first, del);
			return (NULL);
		}
		ft_lstadd_back(&new_first, new_node);
		lst = lst-> next;
	}
	return (new_first);
}

/*void	*map_function(void *content)
{
	int	*new_value;

	new_value = (int *)malloc(sizeof(int));
	if (!new_value)
		return (NULL);
	*new_value = (*(int *)content) * 2; // Esempio: raddoppia il valore intero
	return (new_value);
}

void	del_function(void *content)
{
	free(content);
}

int main()
{
	t_list	*lst = NULL;
	t_list	*mapped_list = NULL;

	for (int i = 1; i <= 5; ++i)
	{
		int *value = (int *)malloc(sizeof(int));
		*value = i;
		ft_lstadd_back(&lst, ft_lstnew(value));
	}

	mapped_list = ft_lstmap(lst, map_function, del_function);

	t_list *current = mapped_list;
	while (current)
	{
		printf("%d ", *(int *)(current->content));
		current = current->next;
	}
	printf("\n");

	ft_lstclear(&lst, del_function);
	ft_lstclear(&mapped_list, del_function);
	return (0);
}*/
