/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:05:30 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 12:49:33 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_arraylen(char *str, char *to_find)
{
	char	*temp;
	int		cont;

	cont = 0;
	temp = str;
	while (temp != NULL)
	{
		temp = ft_strstr(str, to_find);
		cont++;
		temp += ft_strlen(to_find);
	}
	return (cont);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split_pool(char *str, char *charset)
{
	char	**strs;
	char	*temp;
	int		len;
	int		i;

	strs = (char **)malloc((ft_arraylen(str, charset) + 2) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	temp = ft_strstr(str, charset);
	while (temp != NULL)
	{
		len = temp - str;
		strs[i] = (char *)malloc(len + 1);
		ft_strncpy(strs[i], str, len);
		strs[i][len] = '\0';
		str = temp + ft_strlen(charset);
		i++;
	}
	strs[i] = (char *)malloc(ft_strlen(str) + 1);
	if (!strs[i])
		return (NULL);
	ft_strncpy(strs[i], str, ft_strlen(str));
	return (strs[i + 1] = NULL, strs);
}
