/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:07 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/13 16:13:08 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int					count;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		count = (int)n - 1;
		while (count >= 0)
		{
			*(char *)(dst + count) = *(char *)(src + count);
			count--;
		}
	}
	else
	{
		count = 0;
		while (count < (int)n)
		{
			*(char *)(dst + count) = *(char *)(src + count);
			count++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	stringadst[] = "zzzzbbbbcccc";
	char	*stringasrc = "ciao peppino";
	
	printf("String prima di ft_memmove: %s\n", stringadst);
    ft_memmove(stringadst, stringasrc, 4);
    printf("String dopo ft_memmove: %s\n", stringadst);
    
    char	numdst[] = "1111222233334444";
	char	*numsrc = "9999";
	
	printf("Array prima di ft_memmove: %s\n", numdst);
    ft_memmove(numdst, numsrc, 4);
    printf("Array dopo ft_memmove: %s\n", numdst);
	
	return (0);
}*/
