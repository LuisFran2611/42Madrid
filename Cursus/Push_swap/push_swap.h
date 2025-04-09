/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanchez <lsanchez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:06:48 by lsanchez          #+#    #+#             */
/*   Updated: 2025/04/09 13:06:57 by lsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/ft_printf/includes/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

int					get_stack_size(t_node *stack);
int					get_max_bits(t_node *stack);
void				radix_sort(t_node **stack_a, t_node **stack_b);
void				sort_stacks(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);
int					is_sorted(t_node **stack);
void				index_stack(t_node **stack);
t_node				*get_next_min(t_node **stack);
int					get_min(t_node **stack, int val);
int					index_distance_head(t_node **stack, int index);
void				sort_5(t_node **stack_a, t_node **stack_b);
void				sort_4(t_node **stack_a, t_node **stack_b);
void				sort_3(t_node **stack_a);
void				sort_312(t_node **stack_a, t_node *head, int min);
void				sort_231(t_node **stack_a, t_node *head, int min);
void				sort_132(t_node **stack_a);
t_node				*ft_stacklast(t_node *head);
int					ft_stacksize(t_node *head);
int					ft_isrepit(t_node **stack);
void				simple_sort(t_node **stack_a, t_node **stack_b);
void				free_stack(t_node **stack);
void				free_stacks(t_node **stack_a, t_node **stack_b);
int					ft_isrepit(t_node **stack);
void				check_repit(t_node **stack);

#endif
