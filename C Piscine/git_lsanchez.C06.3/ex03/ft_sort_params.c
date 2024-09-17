/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:47:19 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/20 13:07:01 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putstr(int argc, char **str)
{
	int	length;
	int	i;

	i = 1;
	length = 0;
	while (i < argc)
	{
		length = 0;
		while (str[i][length] != '\0')
		{
			length++;
		}
		write(1, str[i], length);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*temp;
	int		j;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			j = 1;
			while (j < argc - i)
			{
				if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				{
					temp = argv[j];
					argv[j] = argv[j + 1];
					argv[j + 1] = temp;
				}
				j++;
			}
			i++;
		}
	}
	ft_putstr(argc, argv);
}
