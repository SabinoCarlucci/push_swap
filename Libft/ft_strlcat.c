/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:07:16 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/14 16:07:18 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cdst;
	size_t	csrc;
	size_t	ldst;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen((char *)src);
	cdst = ldst;
	csrc = 0;
	if (ldst < (size - 1) && size > 0)
	{
		while (src[csrc] != '\0' && (ldst + csrc) < (size - 1))
		{
			dst[cdst] = src[csrc];
			cdst++;
			csrc++;
		}
		dst[cdst] = '\0';
	}
	if (ldst >= size)
		ldst = size;
	return (ldst + lsrc);
}
/*
void test(int size)
{
	char	*start = "bcd";
	char	finish[4] = "a";
	int		lun = ft_strlcat(finish, start, size);
	
	printf("Ho copiato %s su %s lunghezza %d caratteri\n", start, finish, lun);
}

int main(void)
{
	test(7);
	test(5);
	test(4);
	test(1);
	test(0);
	
	return (0);
}*/
