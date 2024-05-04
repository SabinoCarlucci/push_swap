/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:58:56 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/14 10:58:58 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (src[count] != '\0' && (count + 1) < size)
	{
		dst[count] = src[count];
		count++;
	}
	if (size > 0)
		dst[count] = '\0';
	count = 0;
	while (src[count] != '\0')
		count++;
	return (count);
}

/*
void test(int size)
{
	char	start[] = "ciao, mamma di Mimmo";
	char	finish[21];
	int		lun = ft_strlcpy(finish, start, size);
	
	printf("Ho copiato %s su %s lunghezza %d caratteri\n", start, finish, lun);
}

int main(void)
{
	test(21);
	test(5);
	test(1);
	test(0);
	
	return (0);
}*/
