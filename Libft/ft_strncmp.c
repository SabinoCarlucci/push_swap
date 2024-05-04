/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:27:13 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/16 12:27:15 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0') && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
void	test(const char *s1, const char *s2, size_t n)
{
	printf("primi %zu caratteri delle stringhe %s e %s, risultato %d\n", 
	n, s1, s2, ft_strncmp(s1, s2, n));
}

int	main(void)
{
	test("casa", "casb", 4);
	test("casa", "casb", 5);
	test("casa", "casb", 3);
	test("basa", "casb", 0);
	printf("strncmp per confronto %d\n", strncmp("aasa", "cbsb", 0));
	test("casa", "cbsb", 1);
	printf("strncmp per confronto %d\n", strncmp("casa", "cbsb", 2));
	return (0);
}*/
