/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:43:09 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/22 11:14:51 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copia;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	size++;
	copia = (char *)malloc (size * sizeof(char));
	if (copia == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copia[i] = src[i];
		i++;
	}
	return (copia);
}

/*#include <stdio.h>
int main() {
    // Caso 1: Cadena normal
    char str1[] = "Hello, World!";
    char *dup1 = ft_strdup(str1);
    printf("Original: %s\nDuplicada: %s\n", str1, dup1);
    free(dup1);

    // Caso 2: Cadena vacía
    char str2[] = "";
    char *dup2 = ft_strdup(str2);
    printf("Original: '%s'\nDuplicada: '%s'\n", str2, dup2);
    free(dup2);

    // Caso 3: Cadena con caracteres especiales
    char str3[] = "¡Hola, Mundo!";
    char *dup3 = ft_strdup(str3);
    printf("Original: %s\nDuplicada: %s\n", str3, dup3);
    free(dup3);

    // Caso 4: Cadena con un solo carácter
    char str4[] = "A";
    char *dup4 = ft_strdup(str4);
    printf("Original: %s\nDuplicada: %s\n", str4, dup4);
    free(dup4);

    return 0;
}*/
