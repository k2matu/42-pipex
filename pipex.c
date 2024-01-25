/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:06:33 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/01/25 13:54:44 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	xcute_cmd1(char *file, char *cmd1)
{
	char **args;
	char **arr;
	char *path;
	
	args = ft_split(cmd1, ' ');
	path = ft_strjoin("/bin/", args[0]);
	execve(path, args, NULL);
	perror("execve");
}

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;

	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
		xcute_cmd1(argv[0], argv[1]);

	return (0);
}
