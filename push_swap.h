
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*values;
	int	size;
	int	res_size;
}	t_stack;

t_stack	*putargstostack(t_stack *stack_a, char **argv, int argc);
t_stack	*castandfill(t_stack *stack_a, char **str, int size);
int		shiftbottom(t_stack *stack);
int		shifttop(t_stack *stack);
int		sb(t_stack *stack_b);
int		sa(t_stack *stack_a);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack *stack_a);
int		rb(t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
void	handle_error(t_stack *stack_a, t_stack *stack_b);
void	parsingErr();
void	sort_b(t_stack *stack_b);
void	quicksort(t_stack *stack_a, t_stack *stack_b);
void	fullsort(t_stack *stack_a, t_stack *stack_b);
t_stack	*init_b(t_stack *stack_a, t_stack *stack_b);
int		getmin(t_stack *stack);
int		getmax(t_stack *stack);
int		getmaxvalue(int size1, int size2);
int		get_member_to_push(t_stack *stack, int *group);
int		get_member_to_push_and_sort(t_stack *stack_a, t_stack *stack_b,
			int *group);
int		**get_created_groupes(t_stack *stack_a, t_stack *stack_b, int size);
void	push_groupes(t_stack *stack_a, t_stack *stack_b, int *groupe);
void	reverse_rotate_stacks(t_stack *b, t_stack *a, int items[2],
			int places[2]);
void	rotate_stacks(t_stack *b, t_stack *a, int items[2], int places[2]);
int		is_ingroup(t_stack *stack, int *group);
int		getfirst(t_stack *b, t_stack *a, int limits[2], int member);
void	push_and_sort_group(t_stack *stack_a, t_stack *stack_b, int *group);
void	move_index(t_stack *stack_b, int index, int value);
void	sort_a(t_stack *stack_a);
void	push_allvalues_toa(t_stack *stack_a, t_stack *stack_b);
void	push_rotate_to_top_b(t_stack *stack_a, t_stack *stack_b);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
int		b_is_sorted(t_stack *stack_a, t_stack *stack_b);
void	delete(t_stack *stack_b, int **groups, int i);
int		calcfirst(int index, int size, int isa);
void	push_and_rotate_handler(t_stack *stack_a, t_stack *stack_b);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
int	ft_isdigit(int d);
#endif
