/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:21:57 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/22 11:11:39 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	total_length(char *str)
{
	int	len_total;

	len_total = 0;
	while (str[len_total])
		len_total++;
	return (len_total);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*p;

	p = dest;
	while (*p)
	{
		p++;
	}
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

void	cat(int size, char *result, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		result = ft_strcat (result, strs[i]);
		if (i != size - 1)
			result = ft_strcat (result, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len_sep;
	int		len_t;
	int		i;

	len_t = 0;
	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	len_sep = total_length(sep);
	i = 0;
	while (i < size)
	{
		len_t += total_length(strs[i]);
		i++;
	}
	len_t += i * len_sep + 1;
	result = (char *)malloc (len_t);
	result[0] = '\0';
	cat (size, result, strs, sep);
	return (result);
}
/*#include <stdio.h>
int main() {
    // Caso 1: Unión de 3 cadenas con un separador
    char *strs1[] = {"Hello", "World", "42"};
    char *sep1 = ", ";
    char *result1 = ft_strjoin(3, strs1, sep1);
    printf("Resultado 1: %s\n", result1);
    free(result1);

    // Caso 2: Sin cadenas de entrada (size = 0)
    char *strs2[] = {};
    char *sep2 = ", ";
    char *result2 = ft_strjoin(0, strs2, sep2);
    printf("Resultado 2: '%s'\n", result2);
    free(result2);

    // Caso 3: Una sola cadena sin separador
    char *strs3[] = {"Solo"};
    char *sep3 = "";
    char *result3 = ft_strjoin(1, strs3, sep3);
    printf("Resultado 3: %s\n", result3);
    free(result3);

    return 0;
}*/
