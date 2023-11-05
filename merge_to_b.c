/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/05 17:40:47 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->stack[0] > stack_a->stack[0])
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
	rb_wrapper(stack_b->stack, stack_b->height);
	while (stack_b->stack[stack_b->height - 1] < stack_b->stack[0])
	{
		if (stack_b->stack[0] > stack_a->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
	while (stack_b->stack[stack_b->height - 1] < stack_a->stack[0])
	{
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
}