/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:48:41 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/27 08:36:56 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s;

	if (*to_find == '\0')
	{
		return ((char *)str);
	}
	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		s = j + i;
		while (str[s] && to_find[j] && (str[s] == to_find[j]) && s < n)
		{
			j++;
			s++;
		}
		if (to_find[j] == '\0')
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
