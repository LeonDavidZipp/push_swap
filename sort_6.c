/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/05 17:35:19 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_6(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		height;

	i = 0;
	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	height = 3 - (stack_a->height <= 5);
	while (i++ < height)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	sort_3_a(stack_a);
	sort_3_b(stack_b);
	while (stack_b->height > 0)
	{
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&stack_a->height, &stack_b->height);
	}
}

1 2 3
-5 10 11