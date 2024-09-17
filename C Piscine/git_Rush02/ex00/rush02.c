/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:32:30 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/25 20:41:01 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "proces_array.h"

int	is_not_a_pos_num(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (is_not_a_pos_num(argv[1]))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		proces_num(argv[1], "numbers.dict");
	}
	else if (argc == 3)
	{
		if (is_not_a_pos_num(argv[2]))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		proces_num(argv[2], argv[1]);
	}
	else
		return (-1);
}
