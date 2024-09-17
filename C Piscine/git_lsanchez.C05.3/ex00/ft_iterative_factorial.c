/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:11:41 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/20 11:21:35 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = 1;
	if (nb == 0)
		return (1);
	if (nb > 0)
	{
		while (nb > 0)
		{
			n = n * nb;
			nb--;
		}
		return (n);
	}
	else
		return (0);
}

/*int main()
{
	int	n;

	n = ft_iterative_factorial(5);
	printf("%d",n);
}*/
