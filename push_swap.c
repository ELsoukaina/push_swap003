
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	i = 0;
	if (argc > 1)
	{
		stack_a = putargstostack(stack_a, argv, argc);
		stack_b = init_b(stack_a, stack_b);
		while (i < stack_a->size)
		{
			i++;
		}
		printf("first a the value is : %d\n", i);
		i = 0;
		while (i < stack_a->size)
		{
			printf("a the value is : %d\n", stack_a->values[i]);
			i++;
		}
		if (stack_a->size < 20)
			quicksort(stack_a, stack_b);
		else
			fullsort(stack_a, stack_b);
		i = 0;
		while (i < stack_a->size)
		{
			printf("a the value is : %d\n", stack_a->values[i]);
			i++;
		}
		printf("the number of : value is %d\n",i);
		// i = 0;
		// while (i < stack_b->size)
		// {
		// 	printf("b : the value is : %d\n", stack_b->values[i]);
		// 	i++;
		// }
		// while(i < stack_a->size)
		// {
		// 	free(stack_a->values[i]);

		// }
		// free(stack_a);
	// if (!stack_b)
	// {
	// 	free(stack_b);
	// 	free(stack_b->values);
	// }
		system("leaks push_swap");
		// while(1)
		// 	pause();
	}
	return (0);
}
