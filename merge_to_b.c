/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/06 18:30:48 by lzipp            ###   ########.fr       */
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

void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	temp = stack_b->stack[0];
	while (stack_a->height > 0 && stack_b->height > 1
		&& temp <= stack_b->stack[0])
	{
		printf("b loop 1\n");
		temp = stack_b->stack[0];
		if (stack_a->stack[0] < stack_b->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
		printf("stack a: ");
		for (int i = 0; i < stack_a->height; i++)
		{
			printf("%d ", stack_a->stack[i]);
		}
		printf("\n");
		printf("stack b: ");
		for (int i = 0; i < stack_b->height; i++)
		{
			printf("%d ", stack_b->stack[i]);
		}
		printf("\n");
	}
	temp = stack_a->stack[0];
	while (stack_a->height > 0 && temp <= stack_a->stack[0])
	{
		printf("b loop 2\n");
		temp = stack_a->stack[0];
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
}
