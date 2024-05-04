/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:14:37 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/13 12:14:39 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*uchars;

	uchars = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		uchars[count] = 0;
		count++;
	}
}
/*
int main() {
    char mystring[] = "Hello, World!";
    int myIntArray[] = {1, 2, 3, 4, 5};

    printf("string prima di ft_bzero: %s\n", mystring);
    ft_bzero(mystring, 3);
    printf("string dopo ft_bzero: %s\n", mystring);

    size_t intArraySize = sizeof(myIntArray) / sizeof(myIntArray[0]);
    printf("Array di interi prima di ft_bzero: ");
    for (size_t i = 0; i < intArraySize; i++) {
        printf("%d ", myIntArray[i]);
    }
    printf("\n");

    ft_bzero(myIntArray, (3 * sizeof(int)));

    printf("Array di interi dopo ft_bzero: ");
    for (size_t i = 0; i < intArraySize; i++) {
        printf("%d ", myIntArray[i]);
    }
    printf("\n");
    return 0;
}*/
