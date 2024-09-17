/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:31:21 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 12:37:46 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_wordcount(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_separator(*str, charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_separator(*str, charset))
			in_word = 0;
		str++;
	}
	return (count);
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

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i[3];

	i[0] = ft_wordcount(str, charset);
	strs = (char **)malloc((i[0] + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i[1] = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		i[2] = 0;
		while (str[i[2]] && !is_separator(str[i[2]], charset))
			i[2]++;
		if (i[2] > 0)
		{
			strs[i[1]] = (char *)malloc(i[2] + 1);
			ft_strncpy(strs[i[1]], str, i[2]);
			strs[i[1]][i[2]] = '\0';
			i[1]++;
			str += i[2];
		}
	}
	return (strs[i[1]] = NULL, strs);
}
