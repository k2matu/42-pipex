/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:23:22 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/02/07 21:40:23 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_path(char **envp, char *str)
{
	char	**path_to_env;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	path_to_env = ft_split(path, ':');
	i = 0;
	while (path_to_env[i])
	{
		path_to_env[i] = ft_strjoin(path_to_env[i], "/");
		path_to_env[i] = ft_strjoin(path_to_env[i], str);
		i++;
	}
	return (path_to_env);
}

char	**parsing_args(char *str)
{
	char	**args;
	int		len;

	args = ft_split(str, ' ');
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

void	error_msg(char *str)
{
	ft_putstr_fd("pipex: ", 2);
	perror(str);
	exit(EXIT_FAILURE);
}
