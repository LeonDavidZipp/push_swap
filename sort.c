/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 22:54:14 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack[0] < stack_b->stack[0])
	{
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
	while (stack_b->stack[stack_b->height - 1] <= stack_b->stack[0])
	{
		if (stack_a->stack[0] < stack_b->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
	while (stack_b->stack[stack_b->height - 1] <= stack_a->stack[0])
	{
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
}

static void	merge_to_a(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->stack[0] < stack_a->stack[0])
	{
		pb_wrapper(stack_b->stack, stack_a->stack,
			&(stack_b->height), &(stack_a->height));
		rb_wrapper(stack_a->stack, stack_a->height);
	}
	while (stack_a->stack[stack_a->height - 1] <= stack_a->stack[0])
	{
		if (stack_b->stack[0] < stack_a->stack[0])
			pb_wrapper(stack_b->stack, stack_a->stack,
				&(stack_b->height), &(stack_a->height));
		rb_wrapper(stack_a->stack, stack_a->height);
	}
	while (stack_a->stack[stack_a->height - 1] <= stack_b->stack[0])
	{
		pb_wrapper(stack_b->stack, stack_a->stack,
			&(stack_b->height), &(stack_a->height));
		rb_wrapper(stack_a->stack, stack_a->height);
	}
}

/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		runs;
	int		stack_flag;

	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	if (distribute_runs(stack_a, stack_b) == 1)
		return ;
	stack_flag = 1;
	while (stack_b->height > 0)
	{
		if (stack_flag == 1)
			merge_to_a(stack_a, stack_b);
		else
			merge_to_b(stack_a, stack_b);
		stack_flag *= -1;
	}
}
