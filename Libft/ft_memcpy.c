/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:24:52 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/13 14:24:53 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*udest;
	unsigned char	*usrc;

	if (!dest && !src)
		return (NULL);
	count = 0;
	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	while (count < n)
	{
		udest[count] = usrc[count];
		count++;
	}
	return (dest);
}
/*
int main() {
    char source[] = "Carlo";
    char destination[] = "Mario, buongiorno!";
    // Copia i primi 6 caratteri da source a destination
    ft_memcpy(destination, source, 5);
    printf("Copied string: %s\n", destination);
    // Copia un array di interi
    int sourceArray[] = {1, 2, 3, 4, 5};
    int destArray[5];
    // Copia gli interi dall'array sourceArray a destArray
    ft_memcpy(destArray, sourceArray, sizeof(sourceArray));
    printf("Copied integers: ");
    for (size_t i = 0; i < sizeof(destArray) / sizeof(destArray[0]); i++) {
        printf("%d ", destArray[i]);
    }
    printf("\n");
    return 0;
}*/
