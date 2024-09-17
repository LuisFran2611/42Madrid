/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:43:40 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/14 19:02:12 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	char	*p;

	p = dest;
	while (*p)
	{
		p++;
	}
	while (*src && n--)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}
