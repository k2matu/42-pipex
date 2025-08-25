/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kale <kale@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:23:22 by kmatjuhi          #+#    #+#             */
/*   Updated: 2025/08/25 12:18:45 by kale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_sstrjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 4) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = '/';
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	free(s1);
	return (dest);
}

static char	**parsing_to_env(char *path, char *str, int *fd)
{
	char	**path_to_env;
	int		i;

	i = 0;
	path_to_env = ft_split(path, ':');
	free(path);
	if (!path_to_env)
	{
		custom_msg("", "malloc failed\n", fd, NULL);
		exit(EXIT_FAILURE);
	}
	while (path_to_env[i])
	{
		path_to_env[i] = ft_sstrjoin(path_to_env[i], str);
		if (!path_to_env[i])
		{
			ft_free_arr(path_to_env);
			custom_msg("", "malloc failed\n", fd, NULL);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (path_to_env);
}

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
	{
		custom_msg(str, ": No such file or directory\n", fd, NULL);
		exit(127);
	}
	path_to_env = parsing_to_env(path, str, fd);
	return (path_to_env);
}
