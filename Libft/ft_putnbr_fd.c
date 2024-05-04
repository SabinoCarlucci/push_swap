/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:41:52 by scarlucc          #+#    #+#             */
/*   Updated: 2023/11/02 17:41:54 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	long	l;

	l = n;
	if (l < 0)
	{
		write(fd, "-", 1);
		l = -l;
	}
	digit = '0' + (l % 10);
	if (l > 9)
		ft_putnbr_fd((l / 10), fd);
	write(fd, &digit, 1);
}
/*
long	ft_power(int base, int p)
{
	long	result;
	
	result = 1;
	if (p == 0)
		return (1);
	if (p == 1)
		return (base);
	while (p > 0)
	{
		result = result * base;
		p--;
	}
	return (result);
}*/