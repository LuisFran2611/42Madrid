#include "push_swap.h"

void sa(t_node **stack_a)
{
    t_node *first;
    t_node *second;

    if (!stack_a || !(*stack_a) || !((*stack_a)->next))
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);
}

void sb(t_node **stack_b)
{
    t_node *first;
    t_node *second;

    if (!stack_b || !(*stack_b) || !((*stack_b)->next))
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    write(1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        t_node *first = *stack_a;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        *stack_a = second;
    }
    if (stack_b && *stack_b && (*stack_b)->next)
    {
        t_node *first = *stack_b;
        t_node *second = first->next;
        first->next = second->next;
        second->next = first;
        *stack_b = second;
    }
    write(1, "ss\n", 3);
}
