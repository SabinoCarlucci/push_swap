/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:31:30 by scarlucc          #+#    #+#             */
/*   Updated: 2023/10/28 16:31:32 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**clean(char **cleanthismatrix, size_t j);
static char	**makematrix(char const *s, char c, size_t n_str, size_t i);

static char	**clean(char **cleanthismatrix, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
	{
		free(cleanthismatrix[i]);
		i++;
	}
	free(cleanthismatrix);
	return (NULL);
}

static char	**makematrix(char const *s, char c, size_t n_str, size_t i)
{
	char	**out;
	size_t	j;
	size_t	startsub;
	size_t	endsub;

	out = malloc(sizeof(char *) * (n_str + 1));
	if (!out)
		return (NULL);
	out[n_str] = NULL;
	j = 0;
	while (j < n_str)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		startsub = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		endsub = i;
		out[j] = ft_substr(s, startsub, (endsub - startsub));
		if (!out[j])
			return (clean(out, j));
		j++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	n_str;

	i = 0;
	n_str = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			n_str++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	i = 0;
	return (makematrix(s, c, n_str, i));
}
//paco -s sbaglia, fai valgrind con questo main e non ci sono leak
/*
int main(void)
{
    char *str = "hello";
    char c = ' ';

	int i = 0;
    char **array = ft_split(str, c);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}*/