/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/30 14:20:51 by kmatjuhi         ###   ########.fr       */
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

void	xcute_cmd1(char *cmd, char **envp, int *fd, char *file)
{
	char	**args;
	char	**path;
	int		i;
	int		file1;

	i = 0;
	args = ft_split(cmd, ' ');
	file1 = open(file, O_RDONLY);
	if (file1 == -1)
		exit (-1);
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(file1);
	path = parsing_path(envp, args[0]);
	while (path[i])
	{
		close(fd[0]);
		execve(path[i], args, envp);
		// perror("execve");
		free(path[i]);
		i++;
	}
}

void	xcute_cmd2(char *cmd, char **envp, int *fd, char *file)
{
	char	**args;
	char	**path;
	int		i;
	int		file2;

	i = 0;
	args = ft_split(cmd, ' ');
	file2 = open(file, O_RDWR | O_CREAT, 0777 | O_TRUNC);
	if (file2 == -1)
		exit (-1);
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(file2);
	close(fd[1]);
	path = parsing_path(envp, args[0]);
	while (path[i])
	{
		execve(path[i], args, envp);
		// perror("execve");
		free(path[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	
	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == -1)
		return (-1);
	if (pid1 == 0)
		xcute_cmd1(argv[2], envp, fd, argv[1]);
	pid2 = fork();
	if (pid2 == 0)
		xcute_cmd2(argv[3], envp, fd, argv[4]);
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	close(fd[0]);
	return (0);
}
