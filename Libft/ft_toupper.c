/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:29:52 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/15 17:29:53 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
void	test(int letter)
{	
	printf("Ho trasformato %d(%c) in %d(%c)\n", letter, 
	(char)letter, ft_toupper(letter), (char)ft_toupper(letter));
}

int	main(void)
{
	test('a');
	test('f');
	test('Z');
	test('9');
	test('&');
	test(99);
	return(0);
}*/