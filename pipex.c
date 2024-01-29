/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/26 11:12:50 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	xcute_cmd1(int file1, int file2, char *cmd, int *fd)
{
	char **args;
	char **arr;
	char *path;
	
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(file1);
	close(file2);
	close(fd[0]);
	args = ft_split(cmd, ' ');
	path = ft_strjoin("/bin/", args[0]);
	execve(path, args, NULL);
	perror("execve");
}

void pipex(char *argv[], int file1, int file2)
{
	int fd[2];
	int	pid1;
	int buffer;

	if (pipe(fd) == -1)
		return (perror("Pipe: "));
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork: "));
	if (pid1 == 0)
		xcute_cmd1(file1, file2, argv[2], fd);
}

int	main(int argc, char *argv[])
{
	int	file1;
	int	file2;
	
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		return (-1);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (file2 == -1)
	{
		close(file1);
		return (-1);
	}
	pipex(argv, file1, file2);
	return (0);
}

