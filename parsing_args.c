/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kale <kale@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:23:22 by kmatjuhi          #+#    #+#             */
/*   Updated: 2025/08/25 13:04:09 by kale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	empty_str(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	j = 0;
	if (i == 0)
		return (1);
	while (str[j] == ' ')
		j++;
	if (i == j)
		return (1);
	return (0);
}

char	**trim_quotes(char **args, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strchr(str, '"') != NULL && str[len - 1] == '"')
	{
		args[1] = ft_trimstr(str, '"');
		args[2] = NULL;
	}
	if (ft_strchr(str, '\'') != NULL && str[len - 1] == '\'')
	{
		args[1] = ft_trimstr(str, '\'');
		args[2] = NULL;
	}
	return (args);
}

char	**parsing_args(char *str, int *fd)
{
	char	**args;

	if (empty_str(str) == 1)
	{
		custom_msg(str, ": command not found\n", fd, NULL);
		exit(127);
	}
	args = ft_split(str, ' ');
	if (!args)
	{
		custom_msg("", "malloc failed\n", fd, NULL);
		exit(EXIT_FAILURE);
	}
	args = trim_quotes(args, str);
	return (args);
}
