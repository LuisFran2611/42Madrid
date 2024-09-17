/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:25:25 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/29 18:26:16 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	cont;

	if (!tab)
		return (0);
	i = 0;
	cont = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			cont++;
		i++;
	}
	return (cont);
}
