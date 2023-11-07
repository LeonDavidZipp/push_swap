/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/07 11:55:29 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (stack_b->stack[0] > stack_a->stack[0])
// 	{
// 		pb_wrapper(stack_a->stack, stack_b->stack,
// 			&(stack_a->height), &(stack_b->height));
// 		rb_wrapper(stack_b->stack, stack_b->height);
// 	}
// 	while (stack_b->stack[stack_b->height - 1] < stack_b->stack[0])
// 	{
// 		if (stack_b->stack[0] > stack_a->stack[0])
// 			pb_wrapper(stack_a->stack, stack_b->stack,
// 				&(stack_a->height), &(stack_b->height));
// 		rb_wrapper(stack_b->stack, stack_b->height);
// 	}
// 	while (stack_b->stack[stack_b->height - 1] < stack_a->stack[0])
// 	{
// 		pb_wrapper(stack_a->stack, stack_b->stack,
// 			&(stack_a->height), &(stack_b->height));
// 		rb_wrapper(stack_b->stack, stack_b->height);
// 	}
// }

// void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	temp;

// 	temp = stack_b->stack[0];
// 	while (stack_a->height > 0 && stack_b->height > 1
// 		&& temp <= stack_b->stack[0])
// 	{
// 		printf("b loop 1\n");
// 		temp = stack_b->stack[0];
// 		if (stack_a->stack[0] < stack_b->stack[0])
// 			pb_wrapper(stack_a->stack, stack_b->stack,
// 				&(stack_a->height), &(stack_b->height));
// 		rb_wrapper(stack_b->stack, stack_b->height);
// 		printf("stack a: ");
// 		for (int i = 0; i < stack_a->height; i++)
// 		{
// 			printf("%d ", stack_a->stack[i]);
// 		}
// 		printf("\n");
// 		printf("stack b: ");
// 		for (int i = 0; i < stack_b->height; i++)
// 		{
// 			printf("%d ", stack_b->stack[i]);
// 		}
// 		printf("\n");
// 	}
// 	temp = stack_a->stack[0];
// 	while (stack_a->height > 0 && temp <= stack_a->stack[0])
// 	{
// 		printf("b loop 2\n");
// 		temp = stack_a->stack[0];
// 		pb_wrapper(stack_a->stack, stack_b->stack,
// 			&(stack_a->height), &(stack_b->height));
// 		rb_wrapper(stack_b->stack, stack_b->height);
// 	}
// }

/*
Merging run A to B means the following:
As long as the top of A is less than the top of B, push A to B. Then rotate B.
When the top of A is greater than the top of B, rotate B, at max until the top of B is greater than the nextmost element.
Rotate again, then push A to B.
If there is only one element in A, rotate B until B > A OR B[0] > B[1], then push A to B.
*/
void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		temp;

	temp = stack_a->stack[0];
	while (temp <= stack_a->stack[0])
	{
		temp = stack_a->stack[0];
		printf("temp: %d\n", temp);
		if (stack_b->stack[0] > stack_a->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		// if (stack_b->stack[0] < stack_a->stack[0]
		// 	&& stack_b->stack[0] < stack_b->stack[1])
		// {
		printf("stack_a0: %d\n", stack_a->stack[0]);
		rb_wrapper(stack_b->stack, stack_b->height);
			// continue ;
		// }
		if (stack_b->height >= 2 && stack_b->stack[0] < stack_a->stack[0]
			&& stack_b->stack[0] > stack_b->stack[1])
		{
			rb_wrapper(stack_b->stack, stack_b->height);
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
				printf("stack_a0: %d\n", stack_a->stack[0]);
		}
		// printf("stack a:	");
		// for (int i = 0; i < stack_a->height; i++) {
		// 	printf("%d, ", stack_a->stack[i]);
		// }
		// printf("\n");
		// // printf("hi");
		// printf("stack b:	");
		// for (int i = 0; i < stack_b->height; i++) {
		// 	printf("%d, ", stack_b->stack[i]);
		// }
		// // printf("hi");
		// printf("\n");
		// else
		// 	break ;
	}
	printf("stack_a0: %d\n", stack_a->stack[0]);
}

// for merging

int main() {
    t_stack *stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
    t_stack *stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));

    // Initialize the heights of the stacks
    stack_a->height = 3;
    stack_b->height = 3;

    // Initialize the stacks with some values
    // int stack_a_values[] = {10, 100, 300, 2, 1};
    // int stack_b_values[] = {-3, 111, 308, 700, 6};
	int stack_a_values[] = {10, 100, 300};
    int stack_b_values[] = {-3, 111, 308};
    stack_a->stack = stack_a_values;
    stack_b->stack = stack_b_values;

    // Call the merge_to_a function
    merge_to_b(stack_a, stack_b);

    // Print the values in stack A after the merge
	printf("stack a:	");
    for (int i = 0; i < stack_a->height; i++) {
        printf("%d, ", stack_a->stack[i]);
    }
	printf("\n");
	// printf("hi");
    printf("stack b:	");
	for (int i = 0; i < stack_b->height; i++) {
        printf("%d, ", stack_b->stack[i]);
    }
	// printf("hi");
    printf("\n");
    return 0;
}