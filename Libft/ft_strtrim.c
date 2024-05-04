/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:09:58 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/26 12:10:01 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_strdup.c"
//#include "ft_strlcpy.c"
//#include "ft_strchr.c"
//#include "ft_strlen.c"
//#include "ft_substr.c"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	trim1;
	unsigned int	trim2;
	char			*out;

	if (!s1 || s1[0] == '\0')
		return (ft_strdup(""));
	if (!set || set[0] == '\0')
		return (ft_strdup(s1));
	i = 0;
	while (ft_strchr(set, (int)s1[i]))
		i++;
	if (i >= ft_strlen(s1) - 1)
		return (ft_strdup(""));
	trim1 = i;
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, (int)s1[i]))
		i--;
	trim2 = i;
	out = ft_substr(s1, trim1, (trim2 - trim1 + 1));
	if (!out)
		return (NULL);
	return (out);
}

/*int main(void)
{
    const char *s1 = "   Hello, world!   ";
    const char *set = " ";

    char *trimmed_str = ft_strtrim(s1, set);

    printf("Stringa originale: \"%s\"\n", s1);
    printf("Set di caratteri da rimuovere: \"%s\"\n", set);
    printf("Stringa trimmata: \"%s\"\n", trimmed_str);

    free(trimmed_str);
    return 0;
}*/