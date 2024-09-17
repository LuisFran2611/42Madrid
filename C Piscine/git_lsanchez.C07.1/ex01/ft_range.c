/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:59:46 by lsanchez          #+#    #+#             */
/*   Updated: 2024/08/22 11:19:38 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*num;

	i = 0;
	num = 0;
	if (min >= max)
		return (NULL);
	num = (int *)malloc ((max - min) * sizeof(int));
	if (num == NULL)
		return (NULL);
	while (min + i < max)
	{
		num[i] = min + i;
		i++;
	}
	return (num);
}

/*#include <stdio.h>
void test_ft_range(int min, int max, int expected_size) {
    int *range = ft_range(min, max);
    if (expected_size == 0) {
        if (range == NULL) {
            printf("ft_range(%d, %d): Test
	    passed (NULL as expected).\n", min, max);
        } else {
            printf("ft_range(%d, %d): Tes
	    t failed (Expected NULL but got non-NULL).\n", min, max);
        }
    } else {
        if (range == NULL) {
            printf("ft_range(%d, %d): Test 
	    failed (Expected array but got NULL).\n", min, max);
        } else {
            printf("ft_range(%d, %d): ", min, max);
            for (int i = 0; i < expected_size; i++) {
                printf("%d ", range[i]);
            }
            printf("(Expected size: %d)\n", expected_size);
            free(range);
        }
    }
}

int main() {
    // Caso 1: min < max, rango normal
    test_ft_range(1, 5, 4); // Espera: 1, 2, 3, 4

    // Caso 2: min == max, rango vacío
    test_ft_range(3, 3, 0); // Espera: NULL

    // Caso 3: min > max, rango inválido
    test_ft_range(10, 5, 0); // Espera: NULL

    // Caso 4: min < max, rango con valores negativos
    test_ft_range(-3, 2, 5); // Espera: -3, -2, -1, 0, 1

    // Caso 5: min < max, rango de un solo elemento
    test_ft_range(0, 1, 1); // Espera: 0

    return 0;
}*/
