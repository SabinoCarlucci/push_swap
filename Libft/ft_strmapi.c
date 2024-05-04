/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:38 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/02 15:20:45 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include "ft_strdup.c"
//#include "ft_strlen.c"
//#include "ft_strlcpy.c"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	count;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	count = 0;
	while (s[count])
	{
		str[count] = f(count, str[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}

/*char	mio_tolower(unsigned int index, char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32 + index - index;
	return (c);
}

int 	main(void)
{
	const char *str = "CHEPALLE";
	char *new_str = ft_strmapi(str, mio_tolower);
	printf("dopo: %s\n", new_str);
}*/
