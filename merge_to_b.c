/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/10 17:45:12 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	merge_helper(int *stack_a, int *stack_b,
	int *height_a, int *height_b)
{
	rb_wrapper(stack_b, *height_b);
	pb_wrapper(stack_a, stack_b, height_a, height_b);
}

void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		temp_a;
	int		temp_b;

	temp_b = stack_b->stack[0];
	temp_a = stack_a->stack[0];
	while (stack_a->height >= 1 && temp_b <= stack_b->stack[0]
		&& temp_a <= stack_a->stack[0])
	{
		temp_a = stack_a->stack[0];
		if (stack_b->stack[0] > stack_a->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		else if (stack_b->stack[0] > stack_b->stack[1]
			&& stack_b->stack[0] < stack_a->stack[0])
			merge_helper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
		temp_b = stack_a->stack[0];
	}
	while (temp_b <= stack_b->stack[0] || stack_b->stack[0] > stack_b->stack[1])
	{
		temp_b = stack_b->stack[0];
		rb_wrapper(stack_b->stack, stack_b->height);
	}
}

// for merging

// int main(int argc, char **argv)
// {
// 	t_stack	*stack_a = make_stack_a(argc, argv);
// 	t_stack	*stack_b = make_stack_b(stack_a);

// 	distribute_runs(stack_a, stack_b);
// 	printf("stack a before merge:	");
// 	for (int i = 0; i < stack_a->height; i++) {
// 	printf("%d, ", stack_a->stack[i]);
// 		}
// 		printf("\n");
// 		// printf("hi");
// 	printf("stack b:	");
// 		for (int i = 0; i < stack_b->height; i++) {
// 	printf("%d, ", stack_b->stack[i]);
// 		}
// 		// printf("hi");
// 	printf("\n");
// 	printf("merging stack a to stack b\n");
// 	merge_to_b(stack_a, stack_b);
// 	// Print the values in stack A after the merge
// 	printf("stack a:	");
// 	for (int i = 0; i < stack_a->height; i++) {
// 	printf("%d, ", stack_a->stack[i]);
// 		}
// 		printf("\n");
// 		// printf("hi");
// 	printf("stack b:	");
// 		for (int i = 0; i < stack_b->height; i++) {
// 	printf("%d, ", stack_b->stack[i]);
// 		}
// 		// printf("hi");
// 	printf("\n");
// 	return 0;
// }
