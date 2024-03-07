/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/07 17:23:34 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	xcute_cmd(char **path, char **envp, char **args, int *fd)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (access(path[i], F_OK) == -1)
			i++;
		else
		{
			if (access(path[i], X_OK) == -1)
			{
				ft_free_arr(path);
				custom_msg(path[i], "Permission denied\n", fd, args);
			}
			execve(path[i], args, envp);
		}
	}
}

static void	is_dir(char **args, char *str, int *fd)
{
	int		fd3;

	fd3 = open(str, O_DIRECTORY);
	if (fd3 != -1)
	{
		close(fd3);
		custom_msg(str, ": is a directory\n", fd, args);
	}
}

static void	parsing(char *cmd, char **envp, int *fd)
{
	char	**args;
	char	**path;
	int		i;

	i = 0;
	args = parsing_args(cmd, fd);
	if (ft_strrchr(args[0], '/'))
	{
		is_dir(args, args[0], fd);
		if (access(args[0], F_OK) != 0)
			custom_msg(args[0], ": No such file or directory\n", fd, args);
		execve(args[0], args, envp);
		custom_msg(args[0], ": Permission denied\n", fd, args);
	}
	path = parsing_path(envp, args[0], fd);
	xcute_cmd(path, envp, args, fd);
	ft_free_arr(path);
	custom_msg(cmd, ": command not found\n", fd, args);
}

static void	pipex(char *argv[], char *envp[], int *fd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		error_msg("", fd, 1, -1);
	if (pid1 == 0)
	{
		file1_open(fd, argv[1]);
		parsing(argv[2], envp, fd);
	}
	pid2 = fork();
	if (pid2 == -1)
		error_msg("", fd, 2, pid1);
	if (pid2 == 0)
	{
		file2_open(fd, argv[4]);
		parsing(argv[3], envp, fd);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	if (argc != 5)
		custom_msg("", "It must take 4 arguments\n", fd, NULL);
	if (pipe(fd) == -1)
		error_msg("", fd, 1, -1);
	pipex(argv, envp, fd);
	return (0);
}
