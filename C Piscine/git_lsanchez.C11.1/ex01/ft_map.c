/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:13:52 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 18:25:34 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int len, int (*f)(int))
{
	int	i;
	int	*new_tab;

	new_tab = (int *)malloc((len) * sizeof(int));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_tab[i] = f(tab[i]);
		i++;
	}
	return (new_tab);
}
