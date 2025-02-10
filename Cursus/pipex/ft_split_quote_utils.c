/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:18:09 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/10 13:32:05 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

const char	*skip_spaces(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

const char	*advance_token(const char *s)
{
	char	quote;

	if (*s == '\'' || *s == '\"')
	{
		quote = *s;
		s++;
		while (*s && *s != quote)
			s++;
		if (*s)
			s++;
	}
	else
	{
		while (*s && *s != ' ' && *s != '\t')
			s++;
	}
	return (s);
}

int	count_tokens(const char *s)
{
	int	count;

	s = skip_spaces(s);
	count = 0;
	while (*s)
	{
		s = advance_token(s);
		count++;
		s = skip_spaces(s);
	}
	return (count);
}

int	token_length(const char *s)
{
	int		len;
	char	quote;

	len = 0;
	if (*s == '\'' || *s == '\"')
	{
		quote = *s;
		s++;
		while (*s && *s != quote)
		{
			len++;
			s++;
		}
	}
	else
	{
		while (*s && *s != ' ' && *s != '\t')
		{
			len++;
			s++;
		}
	}
	return (len);
}

char	*copy_quoted_token(const char **s_ptr, int len)
{
	const char	*s;
	char		quote;
	char		*token;
	int			i;

	s = *s_ptr;
	quote = *s;
	s++;
	token = ft_calloc(len + 1, sizeof(char));
	if (!token)
		return (NULL);
	i = 0;
	while (*s && *s != quote && i < len)
	{
		token[i] = *s;
		i++;
		s++;
	}
	if (*s == quote)
		s++;
	token[len] = '\0';
	*s_ptr = s;
	return (token);
}
