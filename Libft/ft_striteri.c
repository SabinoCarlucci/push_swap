/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:16:23 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/02 16:16:26 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	while (s[count])
	{
		f(count, &s[count]);
		count++;
	}
}

/*void print_char_index(unsigned int index, char *c)
{
	printf("Character at index %u: %c\n", index, *c);
}

int main()
{
	char str[] = "Hello";

	printf("Original string: %s\n", str);

	ft_striteri(str, print_char_index);

	return (0);
}*/