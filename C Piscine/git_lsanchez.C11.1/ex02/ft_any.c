/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:19:02 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 18:26:00 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
