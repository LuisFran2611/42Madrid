/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:42:54 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/09 08:30:46 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_312(t_node **stack_a, t_node *head, int min)
{
	if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_231(t_node **stack_a, t_node *head, int min)
{
	if (head->next->index == min)
		sa(stack_a);
	else
		rra(stack_a);
}

void	sort_132(t_node **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

