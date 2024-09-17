/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:33:04 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/11 20:16:44 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;
	char	a;
	int		i;

	i = 0;
	c = 'z';
	while (i < 26)
	{
		a = c - i;
		write (1, &a, 1);
		i++;
	}
}
