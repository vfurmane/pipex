/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:20:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 21:12:08 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	ft_free_array(void *arr);
char	*ft_getenv(const char *name, char *const *envp);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	**ft_split(const char *str, char sep);
int		ft_strccmp(const char *str1, const char *str2, int chr);
char	*ft_strcdup(const char *str, int chr);
char	*ft_strchr(const char *str, int chr);
size_t	ft_strlen(const char *str);

#endif
