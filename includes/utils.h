/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:20:22 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/15 22:55:11 by vfurmane         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif
