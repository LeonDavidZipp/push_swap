/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:37:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 13:09:52 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	merge_helper(int *stack_a, int *stack_b,
	int *height_a, int *height_b)
{
	ra_wrapper(stack_a, *height_a);
	pa_wrapper(stack_a, stack_b, height_a, height_b);
}

void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		temp_a;
	int		temp_b;

	temp_b = stack_b->stack[0];
	temp_a = stack_a->stack[0];
	while (stack_b->height >= 1 && temp_b <= stack_b->stack[0])
	{
		printf("in first merge a while loop, currently merging %d to A\n", stack_b->stack[0]);
		temp_b = stack_b->stack[0];
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		if (stack_a->stack[0] > stack_a->stack[1]
			&& stack_a->stack[0] < stack_b->stack[0])
			merge_helper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		// if (stack_b->height > 1)
			ra_wrapper(stack_a->stack, stack_a->height);
		temp_a = stack_a->stack[0];
		// printf("trying to put %d on %d\n", stack_b->stack[0], stack_a->stack[0]);
		printf("stack a: ");
		for (int i = 0; i < stack_a->height; i++)
			printf("%d ", stack_a->stack[i]);
		printf("\n");
		printf("stack b: ");
		for (int i = 0; i < stack_b->height; i++)
			printf("%d ", stack_b->stack[i]);
		printf("\n");
	}
	while (stack_a->runs > 1 && (temp_a <= stack_a->stack[0]
			|| stack_a->stack[0] > stack_a->stack[1]))
	{
		temp_a = stack_a->stack[0];
		ra_wrapper(stack_a->stack, stack_a->height);
	}
}
// #include <stdio.h>
// int main() {
//     t_stack *stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
//     t_stack *stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));

//     // Initialize the heights of the stacks
//     stack_a->height = 3;
//     stack_b->height = 2;

//     // Initialize the stacks with some values
//     int stack_a_values[12] = {2, 4, 5, 0, 0, 0, 0,0 ,0 ,0 ,0 ,0};
//     // int stack_b_values[] = {-3, 111, 308, 700, 6};
//     int stack_b_values[12] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     stack_a->stack = stack_a_values;
//     stack_b->stack = stack_b_values;

//     // Call the merge_to_a function
//     merge_to_a(stack_a, stack_b);

//     // Print the values in stack A after the merge
//     for (int i = 0; i < stack_a->height; i++) {
//         printf("%d, ", stack_a->stack[i]);
//     }
// 	// printf("hi");
//     printf("\n");
// 	for (int i = 0; i < stack_b->height; i++) {
//         printf("%d, ", stack_b->stack[i]);
//     }
// 	// printf("hi");
//     printf("\n");
//     return (0);
// }
