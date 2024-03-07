/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatjuhi <kmatjuhi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:31:17 by kmatjuhi          #+#    #+#             */
/*   Updated: 2024/03/07 15:49:47 by kmatjuhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

void	custom_msg(char *cmd, char *str, int *fd, char **args);
void	error_msg(char *str, int *fd, int code, pid_t pid);
void	file1_open(int *fd, char *file);
void	file2_open(int *fd, char *file);
char	**parsing_args(char *str, int *fd);
char	**parsing_path(char **envp, char *str, int *fd);

#endif