/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:47:31 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/16 15:47:32 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*(unsigned char *)(s + count) == (unsigned char)c)
			return ((char *)(s + count));
		count++;
	}
	return (NULL);
}
/*
void	test(const char *str, int c, size_t n)
{
	const char *result = ft_memchr(str, c, n);
	
	if (!ft_memchr(str, c, n))
		printf("Il carattere '%c' non è stato trovato nella stringa '%s'\n",
		 (unsigned char)c, str);
	else
	{
		int index = result - str;
		printf("primo carattere '%c' al posto numero %d della stringa %s\n",
		 c, index, str);
	}
		
}

int	main(void)
{
	const char *prova = "sbcfadefgahi";
	
	test(prova, 97, 5);
	test(prova, 'a', 3);
	test(prova, 'f', 10);
	test(prova, 'z', 3);
	test(prova, '&', 3);
	return(0);
}*/
