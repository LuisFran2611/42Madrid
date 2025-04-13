/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:36:47 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/13 11:05:51 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_printf_case(char c, va_list *args, int *len, int *i)
{
	if (c == 's')
		ft_print_str(va_arg(*args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(*args, int), len);
	else if (c == 'u')
		ft_print_uns_int(va_arg(*args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(*args, int), len, c);
	else if (c == 'p')
		ft_print_ptr(va_arg(*args, size_t), len);
	else if (c == 'c')
		ft_print_char(va_arg(*args, int), len);
	else if (c == '%')
		ft_print_char(c, len);
	else
		(*i)--;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_case(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_print_char(str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
