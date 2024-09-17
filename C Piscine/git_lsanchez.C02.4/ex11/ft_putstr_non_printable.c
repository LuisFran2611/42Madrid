/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:11:34 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/13 20:12:29 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	non_print(char c)
{
	char	buffer[2];

	buffer[0] = "0123456789abcdef"[(c >> 4) & 0xF];
	buffer[1] = "0123456789abcdef"[c & 0xF];
	write(1, &buffer, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
		{
			write (1, &"\\", 1);
			non_print(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
/*int main ()
{
	char	c[20] = "Coucou\ntu vas bien ?";
	
	ft_str_is_printable(c);

}*/
