/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:44:23 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/14 14:06:10 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*c1;
	char	*c2;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str)
	{
		c1 = str;
		c2 = to_find;
		while (*c1 && *c2 && (*c1 == *c2))
		{
			c1++;
			c2++;
		}
		if (*c2 == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
