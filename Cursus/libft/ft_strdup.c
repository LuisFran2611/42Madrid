/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:26:48 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/23 10:27:23 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*copia;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	size++;
	copia = (char *)malloc (size * sizeof(char));
	if (copia == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copia[i] = src[i];
		i++;
	}
	return (copia);
}
