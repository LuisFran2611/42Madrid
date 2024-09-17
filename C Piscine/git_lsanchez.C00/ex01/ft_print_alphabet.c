/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:33:04 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/11 20:14:05 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;
	char	a;	
	int		s;

	c = 'a';
	s = 0;
	while (s < 26)
	{
		a = c + s;
		write(1, &a, 1);
		s++;
	}
}
