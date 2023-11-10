// #include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack {
	int	*stack;
	int	height;
}	t_stack;

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return ((void *)dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*cptr;
	size_t	total;

	total = count * size;
	if ((count != 0 && total / count != size)
		|| (size != 0 && total / size != count))
		return (NULL);
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	cptr = (char *)ptr;
	while (total > 0)
	{
		*cptr = 0;
		cptr++;
		total--;
	}
	return (ptr);
}

void	ra(int *stack_a, int height_a)
{
	int		temp;

	if (height_a <= 1)
		return ;
	temp = stack_a[0];
	ft_memmove(stack_a, &stack_a[1], (size_t)(height_a - 1) * sizeof(int));
	stack_a[height_a - 1] = temp;
}

void	ra_wrapper(int *stack_a, int height_a)
{
	ra(stack_a, height_a);
	write(1, "ra\n", 3);
}

void	pa(int *stack_a, int *stack_b, int *height_a, int *height_b)
{
	if (*height_b <= 0)
		return ;
	ft_memmove(&stack_a[1], stack_a, (size_t)(*height_a) * sizeof(int));
	stack_a[0] = stack_b[0];
	ft_memmove(stack_b, &stack_b[1], (size_t)(*height_b) * sizeof(int));
	stack_b[*height_b - 1] = 0;
	(*height_a)++;
	(*height_b)--;
}
// #include <stdio.h>
void	pa_wrapper(int *stack_a, int *stack_b, int *height_a, int *height_b)
{
	pa(stack_a, stack_b, height_a, height_b);
	write(1, "pa\n", 3);
	// printf("height b and a after pa wrapper: %d %d\n", *height_a, *height_b);
}

void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	// while there is an ongoing reverse run in B and B[0] is comparable to B[1]
	int		temp;

	temp = stack_b->stack[0];
	while (stack_b->height > 1 && temp >= stack_b->stack[0])
	{
		temp = stack_b->stack[0];
		// push B to A if B[0] > A[0]
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		// else rotate A and try again
		else
			ra_wrapper(stack_a->stack, stack_a->height);
	}
	write(1, "am here\n", 8);
	// if height B is 1, rotate A until A[0] > B[0] or A[0] > A[1]
	// 		if A[0] > B[0] push B to A
	// 		else if A[0] > A[1], rotate A once more, then push B to A
	while (stack_b->height == 1 && stack_a->stack[0] > stack_b->stack[0] && stack_a->stack[0] > stack_a->stack[1])
	{
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
	write(1, "am here now\n", 12);
	// if height A == 1
	// 		if A[0] > B[0] push B to A
	// 		else push B to A, then rotate A
	
}

int main() {
    t_stack *stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
    t_stack *stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));

    // Initialize the heights of the stacks
    stack_a->height = 5;
    stack_b->height = 7;

    // Initialize the stacks with some values
    int stack_a_values[12] = {10, 100, 300, 2, 1, 0,0 ,0,0,0,0,0};
    // int stack_b_values[] = {-3, 111, 308, 700, 6};
    int stack_b_values[12] = {6, 5, 4, 700, 308, 111, -3, 0,0,0,0,0};
    stack_a->stack = stack_a_values;
    stack_b->stack = stack_b_values;

    // Call the merge_to_a function
    merge_to_a(stack_a, stack_b);

    // Print the values in stack A after the merge
    for (int i = 0; i < stack_a->height; i++) {
        printf("%d, ", stack_a->stack[i]);
    }
	// printf("hi");
    printf("\n");
	for (int i = 0; i < stack_b->height; i++) {
        printf("%d, ", stack_b->stack[i]);
    }
	// printf("hi");
    printf("\n");
    return (0);
}