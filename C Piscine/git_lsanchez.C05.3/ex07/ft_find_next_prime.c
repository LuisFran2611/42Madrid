/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:15:47 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/20 16:52:47 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	if (nb <= 1)
		return (0);
	n = 2;
	while (n < nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (nb < 2147483647)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (nb);
}
/*int main ()
{
	int	n;
	n = ft_find_next_prime(35);
	printf("%d",n);
}*/
