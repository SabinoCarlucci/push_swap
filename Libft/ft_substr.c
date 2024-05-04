/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:43:50 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/23 17:43:52 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_strdup.c"
//#include "ft_strlcpy.c"
//#include "ft_strchr.c"
//#include "ft_strlen.c"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s[start] && i < len && (size_t)start < ft_strlen(s))
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

/*int main(void)
{
    const char *s = "Hello, world!";
    unsigned int start = 7;
    size_t len = 5;

    char *substring = ft_substr(s, start, len);

    printf("Stringa originale: \"%s\"\n", s);
    printf("Indice di inizio: %u\n", start);
    printf("Lunghezza del sottostringa: %zu\n", len);
    printf("Sottostringa: \"%s\"\n", substring);

    free(substring);
    return 0;
}*/