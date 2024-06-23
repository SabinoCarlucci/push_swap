/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:06:02 by scarlucc          #+#    #+#             */
/*   Updated: 2024/06/23 22:36:14 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)(s + count));
		count++;
	}
	if (s[count] == (char)c)
		return ((char *)(s + count));
	return (NULL);
}
/*
void	test(const char *s, int c)
{
	int index = ft_strchr(s, c) - s;
	
	if (!ft_strchr(s, c))
		printf("Il carattere '%c' non è stato trovato nella stringa '%s'\n",
		 (char)c, s);
	else
		printf("ho trovato il carattere '%c' 
		al posto numero %d della stringa %s\n",
		 (char)c, index, s);
}

int	main(void)
{
	const char *prova = "abcdefghi";
	
	test(prova, 97);
	test(prova, 'a');
	test(prova, 'f');
	test(prova, 'z');
	test(prova, '&');
	return(0);
}*/
