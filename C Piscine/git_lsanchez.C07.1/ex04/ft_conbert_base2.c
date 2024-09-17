/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conbert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:43:09 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/22 10:43:12 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cont_base(char *base)
{
	int	i;
	int	j;	

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && base[j] == '+' && base[j] == '-')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

void	guardar_char(int nbr, int n, char *base)
{
	int	s;

	s = 0;
	if (nbr > 0)
	{
		if (nbr > n)
		{
			s = nbr % n;
			nbr = nbr / n;
			print_recur (nbr, n, base);
			write (1, &base[s], 1);
		}
		else
			write (1, &base[nbr], 1);
	}
	else
	{
		write (1, &"-", 1);
		print_recur (-nbr, n, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = cont_base (base);
	if (n > 1)
	{
		guardar_char(nbr, n, base);
	}
}
