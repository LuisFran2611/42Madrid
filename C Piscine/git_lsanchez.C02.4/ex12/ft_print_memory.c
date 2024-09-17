/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:43:10 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/19 11:10:54 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_dir(void *addr)
{
	long	dir;
	char	buffer[16];	
	int		i;

	dir = (long)addr;
	i = 0;
	while (i < 16)
	{
		buffer[i] = "0123456789abcdef"[(dir >> (60 - 4 * i)) & 0xf];
		i++;
	}
	write (1, &buffer, 16);
	write (1, &":", 1);
	write (1, &" ", 1);
}

void	print_memori(char *str)
{
	char	buffer[5];
	char	byte[2];
	int		i;

	i = 0;
	while (str[i])
	{
		byte[0] = str[i];
		byte[1] = str[i + 1];
		buffer[0] = "0123456789abcdef"[(byte[0] >> 4) & 0xF];
		buffer[1] = "0123456789abcdef"[byte[0] & 0xF];
		buffer[2] = "0123456789abcdef"[(byte[1] >> 4) & 0xF];
		buffer[3] = "0123456789abcdef"[byte[1] & 0xF];
		buffer[4] = ' ';
		write (1, &buffer, 5);
		i = i + 2;
	}
	while (i < 16)
	{
		write (1, &"     ", 5);
		i = i + 2;
	}
}

void	print_cont(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
		{
			write (1, &str[i], 1);
		}
		else
		{
			write (1, ".", 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	cadena[16];
	int		i;
	int		j;

	if (size != 0)
	{
		j = 0;
		while ((unsigned int)j < size)
		{
			i = 0;
			while (i < 16)
			{
				cadena[i] = *((char *)addr + j);
				i++;
				j++;
			}
			cadena[i] = '\0';
			print_dir (addr + j);
			print_memori (cadena);
			print_cont (cadena);
			write (1, &"\n", 1);
		}
	}
	return (addr);
}

/*int 	main()
{
char cadena[92] = "Bonjour les aminches...c. est fou.tout.ce q";

	ft_print_memory((void *)cadena, 92);

}*/
