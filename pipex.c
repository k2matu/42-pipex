/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/30 11:24:10 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void duplicate(int file1, int *fd)
// {
// 	dup2(file1, STDIN_FILENO);
// 	dup2(file2, STDOUT_FILENO);
// 	close(file1);
// 	close(file2);
// 	close(fd[0]);
// }

char	**parsing_PATH(char **envp, char *str)
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

void	xcute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	**path;
	int		i;

	i = 0;
	args = ft_split(cmd, ' ');
	path = parsing_PATH(envp, args[0]);
	while (path[i])
	{
		execve(path[i], args, envp);
		perror("execve");
		free(path[i]);
		i++;
	}
}

void	pipex(char **argv, int file1, char **envp)
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (perror("Pipe: "));
	pid = fork();
	if (pid == -1)
		return (perror("Fork: "));
	if (pid == 0)
		xcute_cmd1(argv[2], envp);
}


int	main(int argc, char *argv[], char *envp[])
{
	int	file1;
	int	file2;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		return (-1);
	pipex(argv, file1, envp);
	return (0);
}

