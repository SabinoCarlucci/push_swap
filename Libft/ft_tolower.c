/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:03:14 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/15 18:03:17 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
void	test(int letter)
{	
	printf("Ho trasformato %d(%c) in %d(%c)\n", letter, 
	(char)letter, ft_tolower(letter), (char)ft_tolower(letter));
}

int	main(void)
{
	test('A');
	test('f');
	test('Z');
	test('9');
	test('&');
	test(99);
	return(0);
}*/