/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:20:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 20:50:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

char	*ft_getenv(const char *name, char *const *envp);
int		ft_strccmp(const char *str1, const char *str2, int chr);
char	*ft_strchr(const char *str, int chr);
size_t	ft_strlen(const char *str);

#endif
