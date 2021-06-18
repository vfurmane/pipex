/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:17:31 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/18 11:30:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_commands(char **argv, t_cmd *cmd1, t_cmd *cmd2)
{
	cmd1->iofd[0] = open(argv[1], O_RDONLY);
	if (cmd1->iofd[0] == -1)
		pipex_stderr_message(argv[1], ": ", strerror(errno), 1);
	cmd2->iofd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd2->iofd[1] == -1)
		pipex_stderr_message(argv[4], ": ", strerror(errno), 1);
	cmd1->args = ft_split(argv[2], ' ');
	if (cmd1->args == NULL)
		return (pipex_stderr_message("Error when parsing the first command: ",
				strerror(errno), "", 1));
	cmd2->args = ft_split(argv[3], ' ');
	if (cmd2->args == NULL)
		return (pipex_stderr_message("Error when parsing the second command: ",
				strerror(errno), "", 1));
	return (0);
}
