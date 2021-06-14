/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:35 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 22:17:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "utils.h"

typedef struct s_cmd
{
	char		*path;
	char		**args;
	int			iofd[2];
}				t_cmd;

int	init_commands(char **argv, t_cmd *cmd1, t_cmd *cmd2);

int	pipex_stderr_message(const char *str1, const char *str2, const char *str3,
		unsigned char ret);

#endif
