/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:28:04 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 19:29:51 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infile_fd;
	int	outfile_fd;

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
	return (0);
}
