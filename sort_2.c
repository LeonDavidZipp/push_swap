/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:01:12 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 22:03:21 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_a(t_stack *stack_a)
{
	if (stack_a->height <= 1)
		return ;
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
}

void	sort_2_b(t_stack *stack_b)
{
	if (stack_b->height <= 1)
		return ;
	if (stack_b->stack[0] > stack_b->stack[1])
		sb_wrapper(stack_b->stack, stack_b->height);
}
