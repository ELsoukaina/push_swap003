
#include "push_swap.h"

int	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size - 1 < 1)
		return (0);
	tmp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = tmp;
	return (1);
}

int	ra(t_stack *stack_a)
{
	return (shifttop(stack_a));
}

int	rra(t_stack *stack_a)
{
	return (shiftbottom(stack_a));
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL)
		handle_error(stack_a, stack_b);
	if (stack_b->size - 1 < 0)
		return (0);
	stack_a->values[stack_a->size] = stack_b->values[stack_b->size - 1];
	stack_a->size++;
	stack_b->size--;
	return (1);
}
