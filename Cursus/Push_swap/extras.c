/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:44:47 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/13 11:18:35 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_node *head)
{
	size_t	i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*ft_stacklast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

int	ft_isrepit(t_node **stack)
{
	t_node	*a;
	t_node	*b;

	if (!stack || !*stack)
		return (0);
	a = *stack;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->value == b->value)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

void	check_repit(t_node **stack)
{
	if (ft_isrepit(stack))
	{
		write(2, "Error\n", 6);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

void	atoi_error(t_node **stack_a)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	exit(EXIT_FAILURE);
}
