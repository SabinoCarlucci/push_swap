/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:09:31 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/17 10:09:32 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
/*
void	test(const void *s1, const void *s2, size_t n)
{
	const char	*str1 = s1;
	const char	*str2 = s2;
	
	printf("confronto primi %zu caratteri di stringhe %s e %s risultato %d\n",
	 n, str1, str2, ft_memcmp(str1, str2, n));
	printf("controllo memcmp %d\n", memcmp(str1, str2, n));
}

int	main(void)
{
	test("abc", "abd", 4);
	test("abc", "abc", 5);
	test("abc", "abd", 1);
	test("abc", "abd", 0);
	test("abc", "zbd", 3);
	return (0);
}*/
