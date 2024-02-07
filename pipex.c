/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/02/07 21:26:07 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	file1_open(int *fd, char *file)
{
	int	file1;

	file1 = open(file, O_RDONLY);
	if (file1 == -1)
		error_msg(file);
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(file1);
}

static void	file2_open(int *fd, char *file)
{
	int	file2;

	file2 = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (file2 == -1)
		error_msg(file);
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(file2);
}

static void	xcute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	**path;
	int		i;
	int		ok;

	if (cmd[0] == '\0')
		error_msg("");
	i = -1;
	args = parsing_args(cmd);
	path = parsing_path(envp, args[0]);
	while (path[++i])
	{
		ok = access(path[i], X_OK);
		if (ok == -1)
			free(path[i]);
		else
			execve(path[i], args, envp);
	}
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": Command not found\n", 2);
	exit(126);
}

void	pipex(char *argv[], char *envp[], int *fd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		error_msg("");
	if (pid1 == 0)
	{
		file1_open(fd, argv[1]);
		xcute_cmd(argv[2], envp);
	}
	pid2 = fork();
	if (pid2 == -1)
		error_msg("");
	if (pid2 == 0)
	{
		file2_open(fd, argv[4]);
		xcute_cmd(argv[3], envp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	if (argc != 5)
		error_msg("It must take 4 arguments");
	if (pipe(fd) == -1)
		error_msg("");
	pipex(argv, envp, fd);
	close(fd[1]);
	close(fd[0]);
	return (0);
}
