/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:06:53 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/13 11:24:45 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_node **stack, int num)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		atoi_error(stack);
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

int	atoi_int(const char *str,t_node **stack_a)
{
	long long	result;
	int			i[2];

	result = 0;
	i[1] = 1;
	i[0] = 0;
	while (str[i[0]] && (str[i[0]] == ' '))
		i[0]++;
	if (str[i[0]] == '-' || str[i[0]] == '+')
	{
		if (str[i[0]] == '-')
			i[1] = -1;
		i[0]++;
	}
	while (str[i[0]] && (str[i[0]] >= '0' && str[i[0]] <= '9'))
	{
		result = result * 10 + (str[i[0]] - '0');
		if (result * i[1] > INT_MAX || result * i[1] < INT_MIN)
		{
			atoi_error(stack_a);
		}
		i[0]++;
	}
	return ((int)(result * i[1]));
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
		num = atoi_int(split[j],stack_a);
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
		if (*split == NULL)
			atoi_error(stack_a);
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
