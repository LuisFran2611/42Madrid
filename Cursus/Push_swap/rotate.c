#include "push_swap.h"

void ra(t_node **stack_a)
{
    t_node *first;
    t_node *last;

    if (!stack_a || !(*stack_a) || !((*stack_a)->next))
        return;
    first = *stack_a;
    *stack_a = first->next;
    first->next = NULL;
    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
}
void rb(t_node **stack_b)
{
    t_node *first;
    t_node *last;

    if (!stack_b || !(*stack_b) || !((*stack_b)->next))
        return;
    first = *stack_b;
    *stack_b = first->next;
    first->next = NULL;
    last = *stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "rb\n", 3);
}
void rr(t_node **stack_a, t_node **stack_b)
{
    // Rotar stack_a sin mostrar mensaje individual
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        t_node *first = *stack_a;
        *stack_a = first->next;
        first->next = NULL;
        t_node *last = *stack_a;
        while (last->next)
            last = last->next;
        last->next = first;
    }
    if (stack_b && *stack_b && (*stack_b)->next)
    {
        t_node *first = *stack_b;
        *stack_b = first->next;
        first->next = NULL;
        t_node *last = *stack_b;
        while (last->next)
            last = last->next;
        last->next = first;
    }
    write(1, "rr\n", 3);
}
