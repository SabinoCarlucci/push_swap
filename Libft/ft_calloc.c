/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:59:50 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/18 12:59:53 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_bzero.c"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	p = (void *)malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

/*int main(void)
{
    size_t nmemb = 5;
    size_t size = sizeof(int);
    int *arr = ft_calloc(nmemb, size);

    if (arr)
    {
        for (size_t i = 0; i < nmemb; i++)
        {
            printf("arr[%zu] = %d\n", i, arr[i]);
        }
        free(arr);
    }
    else
    {
        printf("Non funziona\n");
    }

    return 0;
}*/