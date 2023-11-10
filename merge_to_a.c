/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:37:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/10 16:47:30 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	merge_to_a_old(t_stack *stack_a, t_stack *stack_b)
{
	// while there is an ongoing reverse run in B and B[0] is comparable to B[1]
	int		temp_a;
	int		temp_b;

	temp_a = stack_a->stack[0];
	temp_b = stack_b->stack[0];
	while (stack_b->height >= 1 && temp_b >= stack_b->stack[0] && temp_a <= stack_a->stack[0])
	{
		printf("before:\n");
		printf("temp_a: %d\ntemp_b: %d\na0: %d\nb0: %d, b1: %d\n", temp_a, temp_b, stack_a->stack[0], stack_b->stack[0], stack_b->stack[1]);
		temp_b = stack_b->stack[0];
		temp_a = stack_a->stack[0];
		// push B to A if B[0] > A[0]
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		// else rotate A and try again
		// else
		// write(1, "am here now first\n", 18);
		else
			ra_wrapper(stack_a->stack, stack_a->height);
		printf("after:\n");
		printf("temp_a: %d\ntemp_b: %d\na0: %d\nb0: %d, b1: %d\n", temp_a, temp_b, stack_a->stack[0], stack_b->stack[0], stack_b->stack[1]);
		printf("stack_a:");
		for (int i = 0; i < stack_a->height; i++) {
			printf("%d, ", stack_a->stack[i]);
		}
	printf("\n------------------\n");
	}
	// write(1, "am here\n", 8);
	// if height B is 1, rotate A until A[0] > B[0] or A[0] > A[1]
	// 		if A[0] > B[0] push B to A
	// 		else if A[0] > A[1], rotate A once more, then push B to A
	while (stack_b->height == 1)
	{
		while (stack_a->stack[0] < stack_b->stack[0] && stack_a->stack[0] < stack_a->stack[1])
		{
			// printf("a0: %d, a1: %d, b0: %d\n", stack_a->stack[0], stack_a->stack[1], stack_b->stack[0]);
			// write(1, "am here now loop\n", 17);
			ra_wrapper(stack_a->stack, stack_a->height);
		}
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack, &(stack_a->height), &(stack_b->height));
		else if (stack_a->stack[0] > stack_a->stack[1])
		{
			ra_wrapper(stack_a->stack, stack_a->height);
			pa_wrapper(stack_a->stack, stack_b->stack, &(stack_a->height), &(stack_b->height));
		}
	}
	// write(1, "am here now\n", 12);
	// temp_a = stack_a->stack[0];
	// while (temp_a <= stack_a->stack[0])
	// {
	// 	write(1, "am here now loop\n", 17);
	// 	temp_a = stack_a->stack[0];
	// 	ra_wrapper(stack_a->stack, stack_a->height);
	// }
	// if height A == 1
	// 		if A[0] > B[0] push B to A
	// 		else push B to A, then rotate A
	
}

void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		temp_a;
	int		temp_b;

	temp_b = stack_b->stack[0];
	temp_a = stack_a->stack[0];
	while (stack_b->height >= 1 && temp_a <= stack_a->stack[0] && temp_b <= stack_b->stack[0])
	{
		temp_b = stack_b->stack[0];
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		else if (stack_a->stack[0] > stack_a->stack[1] && stack_a->stack[0] < stack_b->stack[0])
		{
			ra_wrapper(stack_a->stack, stack_a->height);
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		}
		ra_wrapper(stack_a->stack, stack_a->height);
		temp_a = stack_a->stack[0];
	}
	while (temp_a <= stack_a->stack[0])
	{
		temp_a = stack_a->stack[0];
		ra_wrapper(stack_a->stack, stack_a->height);
	}
}

int main() {
    t_stack *stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
    t_stack *stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));

    // Initialize the heights of the stacks
    stack_a->height = 4;
    stack_b->height = 2;

    // Initialize the stacks with some values
    int stack_a_values[12] = {10, 100, 600, 700, 0, 0, 0,0 ,0 ,0 ,0 ,0};
    // int stack_b_values[] = {-3, 111, 308, 700, 6};
    int stack_b_values[12] = {3, 100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
