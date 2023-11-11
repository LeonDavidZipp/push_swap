/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 12:02:19 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_6(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	if (stack_a->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	if (stack_b->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	if (stack_b->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	sort_3_a(stack_a);
	printf("a after sort: ");
	for (int i = 0; i < stack_a->height; i++)
	{
		printf("%d ", stack_a->stack[i]);
	}
	printf("\nsorting b\n");
	sort_3_b(stack_b);
	if (stack_b->height > 0)
		merge_to_a(stack_a, stack_b);
}
