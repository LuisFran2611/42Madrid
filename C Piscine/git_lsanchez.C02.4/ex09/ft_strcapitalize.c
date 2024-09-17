/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:11:34 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/19 11:11:44 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	check_up(char c_b, char c)
{
	if (c_b < '0' || (c_b > '9' && c_b < 'A' ))
	{
		c = c - ('a' - 'A');
	}
	else if (c_b > 'Z' && c_b < 'a')
	{
		c = c - ('a' - 'A');
	}
	else if (c_b > 'z' && c_b <= 127)
	{
		c = c - ('a' - 'A');
	}
	return (c);
}

char	check_down(char c_b, char c)
{
	if (c_b >= 'a' && c_b <= 'z')
	{
		c = c + ('a' - 'A');
	}
	else if (c_b >= 'A' && c_b <= 'Z')
	{
		c = c + ('a' - 'A');
	}
	else if (c_b >= '0' && c_b <= '9')
	{
		c = c + ('a' - 'A');
	}
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && i == 0)
		{
			str[i] = str[i] - ('a' - 'A');
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = check_up (str[i - 1], str[i]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = check_down (str[i - 1], str[i]);
		}
		i++;
	}
	return (str);
}

/*int	main ()
{
	char c[62] = "saLut, coMMent Tu vas ? 42mOts quarante-deux; cinquante+et+un";

	ft_strcapitalize(c);

	write(1, c, 62);
	
}*/
