/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:54:59 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/29 18:26:01 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len[3];
	char	*dest;

	len[0] = 0;
	while (s1[len[0]] && is_in_set(s1[len[0]], set))
		len[0]++;
	if (s1[len[0]] == '\0')
	{
		dest = (char *)malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	len[1] = ft_strlen(s1) - 1;
	while (len[1] > len[0] && is_in_set(s1[len[1]], set))
		len[1]--;
	len[2] = len[1] - len[0] + 1;
	dest = (char *)malloc(len[2] + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, &s1[len[0]], len[2]);
	dest[len[2]] = '\0';
	return (dest);
}
