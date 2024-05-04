/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:08:37 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/17 12:08:39 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		i = 0;
		j = 0;
		while (big[i] == little[j] && big[i] && little[j] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
void	test(const char *big, const char *little, size_t len)
{
	const char *result = ft_strnstr(big, little, len);
	
	if (!ft_strnstr(big, little, len))
		printf("little non ha riscontri in big\n");
	else if (ft_strnstr(big, little, len) == big)
		printf("little era vuota\n");
	else
	{
		int index = result - big;
		printf("trovata stringa %s dentro %s in posizione numero %d\n", 
		little, big, index);
	}
}

int	main(void)
{
	test("abc", "b", 3);
	test("absdfabfdfabcert", "abc", 13);
	test("lorem ipsum dolor sit amet", "dolor", 15);
	test("absdfabfdfabcert", "", 9);
	return(0);
}*/
/*versione che non crasha
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0 && (!little || little[0] == '\0'))
		return ((char *)big);
	else if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
			p = (char *)&big[i];
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big);
		else
			j = 0;
		i++;
	}
	return (NULL);
}*/