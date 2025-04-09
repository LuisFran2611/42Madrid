/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:06:53 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/09 13:09:52 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_node **stack, int num)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = num;
	new_node->index = -1;
	new_node->next = NULL;
	if (!(*stack))
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	atoi_int(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (int)(result * sign);
}

void	split_numbers(char **split, t_node **stack_a)
{
	int	j;
	int	num;

	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
		{
			write(2, "Error\n", 6);
			while (split[j])
			{
				free(split[j]);
				j++;
			}
			free(split);
			exit(EXIT_FAILURE);
		}
		num = atoi_int(split[j]);
		add_node(stack_a, num);
		free(split[j]);
		j++;
	}
	free(split);
	check_repit(stack_a);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			exit(EXIT_FAILURE);
		split_numbers(split, stack_a);
		i++;
	}
	if (is_sorted(stack_a))
		return (0);
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_b = NULL;
	index_stack(stack_a);
	sort_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
