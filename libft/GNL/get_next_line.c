/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:38:03 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/21 11:52:42 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(char *str, int fd, int i)
{
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * (sizeof(char)));
	if (!buffer)
	{
		if (str)
			free(str);
		return (NULL);
	}
	i++;
	while (i != 0 && !ft_strchr_gnl(str, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			if (str)
				free(str);
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*search_nl(char *str, int i)
{
	char	*dest;

	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*save_str(char *str, int i)
{
	int		j;
	char	*dest;

	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*dest;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = read_buffer(str, fd, i);
	if (!str || !str[i])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	dest = search_nl(str, i);
	if (!dest)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = save_str(str, i);
	return (dest);
}
