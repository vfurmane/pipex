/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:04 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/15 17:15:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

int	execute_command_with_redirections(t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
	int			ret;
	const char	*args[3] = {"grep", "a", NULL};
	char		*PATH;
	int			status;

	PATH = ft_getenv("PATH", envp);
	(void)cmd2;
	ret = fork();
	if (ret < 0)
		return (pipex_stderr_message("Error when forking: ", strerror(errno),
				"", -1));
	else if (ret == 0)
	{
		dup2(cmd1->iofd[0], STDIN_FILENO);
		execve("/bin/grep", (char **)args, envp);
	}
	else
	{
		wait(&status);
		ret = 1;
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int	execute_pipe_command(t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
	int			fds[2];
	int			ret;

	ret = pipe(fds);
	if (ret == -1)
		return (pipex_stderr_message("Error when creating the pipe: ",
				strerror(errno), "", 1));
	cmd1->iofd[1] = fds[1];
	cmd2->iofd[0] = fds[0];
	ret = execute_command_with_redirections(cmd1, cmd2, envp);
	close(cmd1->iofd[0]);
	close(cmd1->iofd[1]);
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	t_cmd	cmd1;
	t_cmd	cmd2;

	(void)argv;
	(void)envp;
	if (argc != 5)
		return (pipex_stderr_message("You must give 4 arguments", "", "", 1));
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
