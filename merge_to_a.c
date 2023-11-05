/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:37:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/05 17:38:25 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack[0] > stack_b->stack[0])
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
	ra_wrapper(stack_a->stack, stack_a->height);
	while (stack_a->stack[stack_a->height - 1] < stack_a->stack[0])
	{
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
	while (stack_a->stack[stack_a->height - 1] < stack_b->stack[0])
	{
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
}