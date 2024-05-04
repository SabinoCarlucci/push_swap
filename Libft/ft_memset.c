/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:15:26 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/11 17:15:29 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*s, int c, size_t	n)
{
	size_t			count;
	unsigned char	*ucharstr;

	ucharstr = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		ucharstr[count] = (unsigned char)c;
		count++;
	}
	return (s);
}
/*
int main() {
    char myString[] = "Hello, World!";
    int myIntArray[] = {1, 2, 3, 4, 5};

    printf("String prima di ft_memset: %s\n", myString);
    ft_memset(myString, 'X', 3);
    printf("String dopo ft_memset: %s\n", myString);

    size_t intArraySize = sizeof(myIntArray) / sizeof(myIntArray[0]);
    printf("Array di interi prima di ft_memset: ");
    for (size_t i = 0; i < intArraySize; i++) {
        printf("%d ", myIntArray[i]);
    }
    printf("\n");

    ft_memset(myIntArray, 0, (3 * sizeof(int)));

    printf("Array di interi dopo ft_memset: ");
    for (size_t i = 0; i < intArraySize; i++) {
        printf("%d ", myIntArray[i]);
    }
    printf("\n");
    return 0;
}*/
