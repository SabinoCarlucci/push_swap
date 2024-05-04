/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:49:14 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/16 11:49:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	count;
	char	*last;

	last = NULL;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			last = (char *)(s + count);
		count++;
	}
	if (s[count] == (char)c)
		last = (char *)(s + count);
	return (last);
}
/*
void	test(const char *s, int c)
{
	int index = ft_strrchr(s, c) - s;
	
	if (!ft_strrchr(s, c))
		printf("Il carattere '%c' non è stato trovato nella stringa '%s'\n",
		 (char)c, s);
	else
		printf("ultimo carattere '%c' al posto numero %d della stringa %s\n",
		 (char)c, index, s);
}

int	main(void)
{
	const char *prova = "abcfadefgahi";
	
	test(prova, 97);
	test(prova, 'a');
	test(prova, 'f');
	test(prova, 'z');
	test(prova, '&');
	return(0);
}*/
