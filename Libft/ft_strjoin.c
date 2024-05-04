/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:40:22 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/25 17:40:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_strlen.c"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		out[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		out[i] = s2[i - lens1];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*int main()
{
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *result = ft_strjoin(s1, s2);

    if (result)
    {
        printf("Concatenated string: %s\n", result);
        free(result); // Ricorda di liberare la memoria allocata!
    }
    else
        printf("Errore durante l'allocazione di memoria.\n");
    return 0;
}*/