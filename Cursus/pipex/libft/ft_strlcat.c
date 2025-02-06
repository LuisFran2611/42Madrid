/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:36:03 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/24 12:51:28 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i;

	size_dest = 0;
	while (size_dest < size && dest[size_dest])
		size_dest++;
	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size_dest == size)
		return (size_dest + size_src);
	i = 0;
	while (src[i] && (size_dest + i < size - 1))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
