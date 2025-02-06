/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:22:41 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 12:44:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c, char charset)
{
	return (c == charset);
}

static int	ft_wordcount(char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_separator(*str, c) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_separator(*str, c))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	**ft_mallocptc(int i, char **strs)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
	return (NULL);
}

static char	*ft_strncpy(char *dest, char *src, int n)
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
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char c)
{
	char	**strs;
	int		i[2];

	strs = (char **)malloc((ft_wordcount(str, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i[0] = 0;
	while (*str)
	{
		while (*str && is_separator(*str, c))
			str++;
		i[1] = 0;
		while (str[i[1]] && !is_separator(str[i[1]], c))
			i[1]++;
		if (i[1] > 0)
		{
			strs[i[0]] = (char *)malloc(i[1] + 1);
			if (strs[i[0]] == NULL)
				return (ft_mallocptc(i[0], strs));
			ft_strncpy(strs[i[0]], str, i[1]);
			i[0]++;
			str += i[1];
		}
	}
	return (strs[i[0]] = NULL, strs);
}
