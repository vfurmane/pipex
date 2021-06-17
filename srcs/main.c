/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:04 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/17 11:42:59 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	t_cmd	cmd1;
	t_cmd	cmd2;

	(void)argv;
	(void)envp;
	if (argc != 5)
		return (pipex_stderr_message("you must give 4 arguments", "", "", 1));
	ret = init_commands(argv, &cmd1, &cmd2);
	if (ret > 0)
		return (ret);
	ret = execute_pipe_command(&cmd1, &cmd2, envp);
	ft_free_array(cmd1.args);
	ft_free_array(cmd2.args);
	close(cmd1.iofd[0]);
	close(cmd2.iofd[1]);
	return (ret);
}
