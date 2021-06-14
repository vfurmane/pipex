/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:03:38 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/14 21:12:47 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strcdup(const char *str, int chr)
{
	int		str_len;
	char	*new_str;
	char	*first_chr;

	first_chr = ft_strchr(str, chr);
	if (first_chr == NULL)
		str_len = ft_strlen(str);
	else
		str_len = first_chr - str;
	new_str = malloc(sizeof(*new_str) * (str_len + 1));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_memcpy(new_str, str, sizeof(*new_str) * str_len);
	new_str[str_len] = '\0';
	return (new_str);
}
