/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kale <kale@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:31:17 by kmatjuhi          #+#    #+#             */
/*   Updated: 2025/08/25 13:04:15 by kale             ###   ########.fr       */
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
void    close_fds(int *fd);
char	**parsing_args(char *str, int *fd);
char	**parsing_path(char **envp, char *str, int *fd);

#endif