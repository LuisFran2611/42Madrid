/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:41:16 by lsanchez          #+#    #+#             */
/*   Updated: 2024/09/29 18:26:31 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_ele, size_t size_ele)
{
	void	*ptr;

	ptr = malloc(num_ele * size_ele);
	if (!ptr)
		return (NULL);
	else
		ft_memset(ptr, 0, num_ele * size_ele);
	return (ptr);
}
