/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:37:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/07 10:21:53 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (stack_a->stack[0] > stack_b->stack[0])
// 	{
// 		pa_wrapper(stack_a->stack, stack_b->stack,
// 			&(stack_a->height), &(stack_b->height));
// 		ra_wrapper(stack_a->stack, stack_a->height);
// 	}
// 	while (stack_a->stack[stack_a->height - 1] < stack_a->stack[0])
// 	{
// 		if (stack_a->stack[0] > stack_b->stack[0])
// 			pa_wrapper(stack_a->stack, stack_b->stack,
// 				&(stack_a->height), &(stack_b->height));
// 		ra_wrapper(stack_a->stack, stack_a->height);
// 	}
// 	while (stack_a->stack[stack_a->height - 1] < stack_b->stack[0])
// 	{
// 		pa_wrapper(stack_a->stack, stack_b->stack,
// 			&(stack_a->height), &(stack_b->height));
// 		ra_wrapper(stack_a->stack, stack_a->height);
// 	}
// }

// void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
// {
// 	int		temp;

// 	temp = stack_b->stack[0];
// 	while (temp <= stack_b->stack[0])
// 	{
// 		temp = stack_b->stack[0];
// 		if (stack_b->stack[0] < stack_a->stack[0]
// 			|| (stack_b->stack[0] > stack_a->stack[0]
// 			&& stack_a->stack[0] > stack_a->stack[1]))
// 			pa_wrapper;
// 		ra;
// 		// 1	if B < A, push B
// 		// 2	else rotate A, then try 1 again
// 	}
// 	while (stack_b->height == 1 && stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
// 	ra;
// 	pa;
// 	ra;
// }

// void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
// {
// 	// first phase: both A and B ar in a run
// 	while (stack_a->stack[0] < stack_a->stack[1]
// 		&& stack_b->stack[0] < stack_b->stack[1])
// 	{
// 		printf("in first loop\n");
// 		if (stack_b->stack[0] < stack_a->stack[0])
// 			pa_wrapper(stack_a->stack, stack_b->stack,
// 				&(stack_a->height), &(stack_b->height));
// 		ra_wrapper(stack_a->stack, stack_a->height);
// 	}
// 	printf("stack a after first loop: ");
// 	for (int i = 0; i < stack_a->height; i++)
// 	{
// 		printf("%d ", stack_a->stack[i]);
// 	}
// 	printf("\n");
// 	printf("stack b: ");
// 	for (int i = 0; i < stack_b->height; i++)
// 	{
// 		printf("%d ", stack_b->stack[i]);
// 	}
// 	printf("\n");
// 	ra_wrapper(stack_a->stack, stack_a->height);
// 	while (!(stack_a->stack[0] < stack_a->stack[1])
// 		&& stack_b->stack[0] < stack_b->stack[1])
// 	{
// 		printf("in second loop\n");
// 		pa_wrapper(stack_a->stack, stack_b->stack,
// 			&(stack_a->height), &(stack_b->height));
// 		ra_wrapper(stack_a->stack, stack_a->height);
// 	}
// 	printf("stack a after second loop: ");
// 	for (int i = 0; i < stack_a->height; i++)
// 	{
// 		printf("%d ", stack_a->stack[i]);
// 	}
// 	printf("\n");
// 	printf("stack b: ");
// 	for (int i = 0; i < stack_b->height; i++)
// 	{
// 		printf("%d ", stack_b->stack[i]);
// 	}
// 	printf("\n");
// 	if (stack_b->stack[0] > stack_a->stack[0])
// 	{
// 		// ra_wrapper(stack_a->stack, stack_a->height);
// 		pa_wrapper(stack_a->stack, stack_b->stack, &(stack_a->height), &(stack_b->height));
// 	}
// }

/*
Merging run A to B means the following:
As long as the top of A is less than the top of B, push A to B. Then rotate B.
When the top of A is greater than the top of B, rotate B, at max until the top of B is greater than the nextmost element.
Rotate again, then push A to B.
If there is only one element in A, rotate B until B > A OR B[0] > B[1], then push A to B.
*/
void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	temp = stack_a->stack[0];
	while (stack_b->height > 0 && stack_a->height > 1
		&& temp <= stack_a->stack[0])
	{
		printf("temp: %d, stack 0: %d\n", temp, stack_a->stack[0]);
		temp = stack_a->stack[0];
		printf("a loop 1\n");
		if (stack_b->stack[0] < stack_a->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
	temp = stack_b->stack[0];
	while (stack_b->height > 0 && temp <= stack_b->stack[0])
	{
		printf("a loop 2\n");
		temp = stack_b->stack[0];
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
}

int main() {
    t_stack *stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
    t_stack *stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));

    // Initialize the heights of the stacks
    stack_a->height = 5;
    stack_b->height = 5;

    // Initialize the stacks with some values
    int stack_a_values[] = {10, 100, 300, 2, 1};
    int stack_b_values[] = {-3, 111, 308, 700, 6};
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
    return 0;
}
