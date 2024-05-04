/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:36:01 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/17 16:36:03 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	out;
	int	sign;
	int	i;

	sign = 1;
	out = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = (out * 10) + (nptr[i] - '0');
		i++;
	}
	return (out * sign);
}
/*
int main() {
    char nptr[] = "-000012$345abc123";
    int numero = atoi(nptr);
    printf("atoi: %d\n", numero);
    
    numero = ft_atoi(nptr);
    printf("ft_atoi: %d\n", numero);
    return 0;
}*/
