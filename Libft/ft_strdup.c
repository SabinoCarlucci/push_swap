/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:18:53 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/18 16:18:55 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_strlcpy.c"
//#include "ft_strlen.c"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen((char *)s);
	d = (char *)malloc((len + 1) * sizeof(*s));
	if (!d)
		return (NULL);
	ft_strlcpy(d, s, len + 1);
	return (d);
}
/*int main()
{
	const char *original = "Hello, World!";
	char *duplicate = ft_strdup(original);

	if (duplicate)
	{
		printf("Originale: %s\n", original);
		printf("Duplicato: %s\n", duplicate);
		free(duplicate);
	}
	else
		printf("qualcosa non va.\n");
	return (0);
}*/
