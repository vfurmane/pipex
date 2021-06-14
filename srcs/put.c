/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:16:59 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 19:28:57 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_stderr_message(const char *str1, const char *str2, const char *str3,
		unsigned char ret)
{
	write(2, "pipex: ", 7);
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, str3, ft_strlen(str3));
	write(2, "\n", 1);
	return (ret);
}
