/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fopen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:24:42 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/07 16:25:01 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file1_open(int *fd, char *file)
{
	int	file1;

	file1 = open(file, O_RDONLY);
	if (file1 == -1)
		custom_msg(file, ": Permission denied\n", fd, NULL);
	dup2(file1, STDIN_FILENO);
	close(file1);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
}

void	file2_open(int *fd, char *file)
{
	int	file2;

	file2 = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (file2 == -1)
		error_msg(file, fd, 2, -1);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}
