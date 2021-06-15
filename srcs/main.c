/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:04 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/15 23:28:18 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_command_in_path(const char *cmd, const char *path)
{
	int		ret;
	char	*path_slash;
	char	*cmd_path;

	path_slash = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(path_slash, cmd);
	free(path_slash);
	if (cmd_path == NULL)
		return (pipex_stderr_message("unexpected error: ",
				strerror(errno), "", -1));
	ret = open(cmd_path, O_RDONLY);
	free(cmd_path);
	if (ret == -1 && errno == 2)
		return (0);
	else
	{
		close(ret);
		return (1);
	}
}

char	*get_command_path(const char *cmd, char **envp)
{
	int		i;
	int		ret;
	char	*PATH;
	char	**path;

	PATH = ft_getenv("PATH", envp);
	path = ft_split(PATH, ':');
	if (path == NULL)
		return ((void *)(uintptr_t)pipex_stderr_message("unexpected error: ",
				strerror(errno), "", 0));
	i = 0;
	while (path[i])
	{
		ret = is_command_in_path(cmd, path[i]);
		if (ret < 0)
			return (NULL);
		else if (ret == 0)
			i++;
		else
			return (ft_strjoin(ft_strjoin(path[i], "/"), cmd));
	}
	return ((void *)(uintptr_t)pipex_stderr_message(cmd, ": command not found",
			"", 0));
}

int	execute_command_with_redirections(t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
	int			ret;
	int			status;

	(void)cmd2;
	ret = fork();
	if (ret < 0)
		return (pipex_stderr_message("error when forking: ", strerror(errno),
				"", -1));
	else if (ret == 0)
	{
		dup2(cmd1->iofd[0], STDIN_FILENO);
		cmd1->path = get_command_path(cmd1->args[0], envp);
		if (cmd1->path == NULL)
			return (1);
		ret = execve(cmd1->path, (char **)cmd1->args, envp);
		exit(pipex_stderr_message(cmd1->args[0], ": ", strerror(errno), 1));
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
		return (pipex_stderr_message("error when creating the pipe: ",
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
