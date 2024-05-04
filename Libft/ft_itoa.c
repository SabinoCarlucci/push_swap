/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:07 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/31 10:56:09 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*fillstring(int counter, int minus, long number, char *str);

static char	*fillstring(int counter, int minus, long number, char *str)
{
	str[counter + minus] = '\0';
	while (counter > 0)
	{
		str[counter - 1 + minus] = '0' + (number % 10);
		number = number / 10;
		counter--;
	}
	if (minus)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		counter;
	int		minus;

	number = n;
	counter = 0;
	minus = (n < 0);
	if (minus)
		number = -number;
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	counter += (number == 0);
	str = (char *)malloc(sizeof(char) * (counter + minus + 1));
	if (!str)
		return (NULL);
	return (fillstring(counter, minus, number, str));
}

/*
void test(int n)
{
	char *result = ft_itoa(n);
	printf("itoa restituisce %s\n", result);
}

int	main(void)
{
	test(0);
	test(123456);
	test(-2147483648);
	return (0);
}*/