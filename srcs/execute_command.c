/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:43:07 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/17 13:59:59 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_command1(t_cmd *cmd, char **envp, int pipe_to_plug)
{
	cmd->pid = fork();
	if (cmd->pid < 0)
		exit(pipex_stderr_message("error when forking: ", strerror(errno),
				"", 1));
	else if (cmd->pid == 0)
	{
		dup2(cmd->iofd[0], STDIN_FILENO);
		dup2(cmd->iofd[1], STDOUT_FILENO);
		close(pipe_to_plug);
		cmd->path = get_command_path(cmd->args[0], envp);
		if (cmd->path == NULL)
			exit(127);
		execve(cmd->path, (char **)cmd->args, envp);
		exit(pipex_stderr_message(cmd->args[0], ": ", strerror(errno), 1));
	}
}

static void	execute_command2(t_cmd *cmd, char **envp, int pipe_to_plug)
{
	cmd->pid = fork();
	if (cmd->pid < 0)
		exit(pipex_stderr_message("error when forking: ", strerror(errno),
				"", 1));
	else if (cmd->pid == 0)
	{
		dup2(cmd->iofd[0], STDIN_FILENO);
		dup2(cmd->iofd[1], STDOUT_FILENO);
		close(pipe_to_plug);
		cmd->path = get_command_path(cmd->args[0], envp);
		if (cmd->path == NULL)
			exit(127);
		execve(cmd->path, (char **)cmd->args, envp);
		exit(pipex_stderr_message(cmd->args[0], ": ", strerror(errno), 1));
	}
}

static void	create_commands_pipe(t_cmd *cmd1, t_cmd *cmd2)
{
	int			fds[2];

	if (pipe(fds) == -1)
		exit(pipex_stderr_message("error when creating the pipe: ",
				strerror(errno), "", 1));
	cmd1->iofd[1] = fds[1];
	cmd2->iofd[0] = fds[0];
}

static int	wait_all_processes_and_plug_pipe(t_cmd *cmd1)
{
	int			ret;
	int			status;
	int			ended_pid;

	ended_pid = 1;
	ret = 0;
	while (ended_pid > 0)
	{
		ended_pid = wait(&status);
		if (ended_pid == cmd1->pid)
			close(cmd1->iofd[1]);
		else if (ended_pid != -1)
		{
			if (WIFEXITED(status))
				ret = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				ret = WTERMSIG(status);
			else
				ret = 1;
		}
	}
	return (ret);
}

int	execute_pipe_command(t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
	int			status;
	int			ret;

	ret = fork();
	if (ret < 0)
		return (pipex_stderr_message("error when forking: ", strerror(errno),
				"", -1));
	else if (ret == 0)
	{
		create_commands_pipe(cmd1, cmd2);
		execute_command1(cmd1, envp, cmd2->iofd[0]);
		execute_command2(cmd2, envp, cmd1->iofd[1]);
		ret = wait_all_processes_and_plug_pipe(cmd1);
		close(cmd1->iofd[0]);
		close(cmd1->iofd[1]);
		exit(ret);
	}
	waitpid(ret, &status, 0);
	ret = 1;
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	return (ret);
}
