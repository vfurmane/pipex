/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/17 11:45:27 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdint.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include "utils.h"

typedef struct s_cmd
{
	char		*path;
	char		**args;
	int			iofd[2];
	int			pid;
}				t_cmd;

int		execute_pipe_command(t_cmd *cmd1, t_cmd *cmd2, char **envp);

int		init_commands(char **argv, t_cmd *cmd1, t_cmd *cmd2);

char	*get_command_path(const char *cmd, char **envp);

int		pipex_stderr_message(const char *str1, const char *str2,
			const char *str3, unsigned char ret);

#endif
