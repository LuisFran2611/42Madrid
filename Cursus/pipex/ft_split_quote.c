/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:18:40 by lsanchez          #+#    #+#             */
/*   Updated: 2025/02/06 19:22:08 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*copy_unquoted_token(const char **s_ptr, int len)
{
	const char	*s;
	char		*token;
	int			i;

	s = *s_ptr;
	token = ft_calloc(len + 1, sizeof(char));
	if (!token)
		return (NULL);
	i = 0;
	while (*s && *s != ' ' && *s != '\t' && i < len)
	{
		token[i] = *s;
		i++;
		s++;
	}
	token[len] = '\0';
	*s_ptr = s;
	return (token);
}

char	*extract_token(const char **s_ptr)
{
	const char	*s;
	int			len;
	char		*token;

	s = skip_spaces(*s_ptr);
	len = token_length(s);
	if (*s == '\'' || *s == '\"')
		token = copy_quoted_token(&s, len);
	else
		token = copy_unquoted_token(&s, len);
	*s_ptr = s;
	return (token);
}

char	**fill_tokens(const char *s, char **result)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = s;
	while (*ptr)
	{
		ptr = skip_spaces(ptr);
		if (!*ptr)
			break ;
		result[i] = extract_token(&ptr);
		if (!result[i])
		{
			free_char_matrix(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split_quote(const char *s)
{
	char	**result;
	int		tokens;

	if (!s)
		return (NULL);
	tokens = count_tokens(s);
	result = ft_calloc(tokens + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_tokens(s, result));
}
