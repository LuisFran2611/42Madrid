/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:02:06 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/15 11:04:27 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	i;

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
