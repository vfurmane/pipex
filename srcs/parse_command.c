/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:42:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/17 11:42:30 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_command_in_path(const char *cmd, const char *path)
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
