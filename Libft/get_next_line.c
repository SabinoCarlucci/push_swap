/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:38:56 by scarlucc          #+#    #+#             */
/*   Updated: 2024/07/30 20:28:54 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_mod(const char *s)
{
	size_t	len;
	char	*d;
	size_t	count;
	size_t	size;

	len = ft_strlen((char *)s);
	size = len + 1;
	d = (char *)malloc(size * sizeof(*s));
	if (!d)
		return (NULL);
	count = 0;
	while (s[count] != '\0' && (count + 1) < size)
	{
		d[count] = s[count];
		count++;
	}
	if (size > 0)
		d[count] = '\0';
	return (d);
}

char	*get_output(char *output)
{
	size_t		i;
	char		*static_buffer;

	i = 0;
	while (output[i] != '\n' && output[i] != '\0')
		i++;
	if (output[i] == '\0' || output[i + 1] == '\0')
		return (0);
	static_buffer = ft_substr(output, i + 1, ft_strlen(output) - i);
	if (*static_buffer == '\0')
	{
		free(static_buffer);
		static_buffer = NULL;
	}
	output[i + 1] = '\0';
	return (static_buffer);
}

char	*read_line(int fd, char *new, char *static_buffer)
{
	char		*temp;
	int			byte_read;

	byte_read = 1;
	while (byte_read != '\0')
	{
		byte_read = read(fd, new, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		if (byte_read == 0)
			break ;
		new[byte_read] = '\0';
		if (!static_buffer)
			static_buffer = ft_strdup_mod("");
		temp = static_buffer;
		static_buffer = ft_strjoin(temp, new);
		free(temp);
		temp = NULL;
		if (ft_strchr(new, '\n'))
			break ;
	}
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*static_buffer;
	char		*output;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	new = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!new)
		return (0);
	output = read_line(fd, new, static_buffer);
	free(new);
	new = NULL;
	if (!output)
		return (NULL);
	static_buffer = get_output(output);
	return (output);
}

/*
 int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	for (int i = 0; i < 10; ++i) {
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
} */

/* int	main(void){
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	for (int i = 0; i < 10; ++i) {
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return(0);
} */
