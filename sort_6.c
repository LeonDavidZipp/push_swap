/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/10 16:59:53 by lzipp            ###   ########.fr       */
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
	height = 2;
	if (stack_a->height == 6)
		height = 3;
	while (i++ < height)
	{
		// if (stack_a->stack[0] > stack_a->stack[1])
		// 	sa(stack_a->stack, stack_a->height);
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	}
	sort_3_a(stack_a);
	sort_3_b(stack_b);
	merge_to_a(stack_a, stack_b);
}
