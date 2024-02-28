/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:23:22 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/02/28 13:36:10 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_path(char **envp, char *str, int *fd)
{
	char	**path_to_env;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	if (!path)
		custom_msg(str, ": No such file or directory\n", fd, 1);
	path_to_env = ft_split(path, ':');
	free(path);
	i = 0;
	if (ft_strrchr(str, '/'))
		str = ft_strrchr(str, '/');
	while (path_to_env[i])
	{
		path_to_env[i] = ft_sstrjoin(path_to_env[i], str);
		i++;
	}
	return (path_to_env);
}

char	**parsing_args(char *str, int *fd)
{
	char	**args;
	int		len;

	if (str[0] == '\0')
		custom_msg(str, "Permission denied\n", fd, 1);
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

void	error_msg(char *str, int *fd, int code)
{
	close(fd[0]);
	close(fd[1]);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	exit(code);
}

void	custom_msg(char *cmd, char *str, int *fd, int code)
{
	close(fd[0]);
	close(fd[1]);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(str, 2);
	exit(code);
}
