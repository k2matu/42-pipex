/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:11:11 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/07 15:51:09 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *str, int *fd, int code, pid_t pid)
{
	close(fd[0]);
	close(fd[1]);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	if (code == 2)
		waitpid(pid, NULL, 0);
	exit(code);
}

void	custom_msg(char *cmd, char *str, int *fd, char **args)
{
	close(fd[0]);
	close(fd[1]);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(str, 2);
	ft_free_arr(args);
	exit(EXIT_FAILURE);
}
