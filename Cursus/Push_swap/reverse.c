/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:06:03 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/09 13:29:58 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		t_node *prev = NULL;
		t_node *last = *stack_a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
			prev->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		t_node *prev = NULL;
		t_node *last = *stack_b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
			prev->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	write(1, "rrr\n", 4);
}
