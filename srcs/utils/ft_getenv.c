/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:46:09 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 20:49:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_getenv(const char *name, char *const *envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strccmp(name, envp[i], '=') == 0)
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}
