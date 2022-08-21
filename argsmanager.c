

#include "push_swap.h"

int	getsizeofargs(char **str)
{
	int	size;

	size = 0;
	while (str[size] != NULL)
		size++;
	return (size);
}

int	getmaxvalue(int size1, int size2)
{
	if (size1 > size2)
		return (size1);
	else
		return (size2);
}

void	handleDupErr(char **str, int size)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (i < size)
	{
		y = i + 1;
		while (y < size)
		{
			if (ft_strncmp(str[i], str[y], getmaxvalue(ft_strlen(str[i]),
						ft_strlen(str[y]))) == 0)
			{
				printf("double\n");
				ft_putstr_fd("Error !", 1);
				exit(0);
			}
			y++;
		}
		i++;
	}
}

t_stack	*castandfill(t_stack	*stack_a, char	**str, int size)
{
	// int	i;

	// i = 0;
	handleDupErr(str, size);
	stack_a = malloc(sizeof(t_stack));
	stack_a->values = malloc(sizeof(int) * size);
	stack_a->size = 0;
	if (!stack_a->values)
		return (NULL);
	while (size > 0)
	{
		stack_a->values[stack_a->size] = ft_atoi(str[size - 1]);
		size--;
		stack_a->size++;
	}
	return (stack_a);
}

t_stack	*putargstostack(t_stack	*stack_a, char	**argv, int argc)
{
	char	*s;
	char	**split_numbers;
	int		i;
	int		size;

	i = 1;
	s = ft_strdup("");
	while (i < argc)
	{	
		if(argv[i][0] == '\0')
		{
			ft_putstr_fd("error \n",1);
			exit(1);
		}
		s = ft_strjoin(s, argv[i]);
		s = ft_strjoin(s, " ");
		i++;
	}
	split_numbers = ft_split(s, ' ');
	//printf("tmp[0] 3amar b : %s",s);
	free(s);
	size = getsizeofargs(split_numbers);
	stack_a = castandfill(stack_a, split_numbers, size);
	//exit(0);
	i = -1;
	while(++i < size)
		free(split_numbers[i]);
	free(split_numbers);
	return (stack_a);
}

// t_stack	*putargstostack(t_stack	*stack_a, char	**argv, int argc)
// {
// 	char	*tmp[2];
// 	char	**split_numbers;
// 	int		i;
// 	int		size;

// 	i = 1;
// 	tmp[0] = ft_strdup(argv[i]);
// 	printf("tmp[0] 3amar b : %s",tmp[0]);
// 	while (++i < argc)
// 	{
		
// 		tmp[1] = ft_strjoin(tmp[0], " ");
// 		free(tmp[0]);
// 		tmp[0] = ft_strjoin(tmp[1], argv[i]);
// 		free(tmp[1]);
// 	}
// 	split_numbers = ft_split(tmp[0], ' ');
// 	size = getsizeofargs(split_numbers);
// 	stack_a = castandfill(stack_a, split_numbers, size);
// 	free(tmp[0]);
// 	return (stack_a);
// }