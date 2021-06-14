/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:04 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 21:18:00 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		infile_fd;
	int		outfile_fd;
	char	*PATH;
	char	**cmd1;
	char	**cmd2;

	(void)argv;
	(void)envp;
	if (argc != 5)
		return (pipex_stderr_message("You must give 4 arguments", "", "", 1));
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		return (pipex_stderr_message(argv[1], ": ", strerror(errno), 1));
	outfile_fd = open(argv[4], O_WRONLY);
	if (outfile_fd == -1)
		return (pipex_stderr_message(argv[4], ": ", strerror(errno), 1));
	PATH = ft_getenv("PATH", envp);
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	ft_free_array(cmd1);
	ft_free_array(cmd2);
	close(infile_fd);
	close(outfile_fd);
	return (0);
}
