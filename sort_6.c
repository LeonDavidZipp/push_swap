/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:07:45 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_2_a(t_stack *stack_a)
{
	if (stack_a->height <= 1)
		return ;
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
}

static void	sort_2_b(t_stack *stack_b)
{
	if (stack_b->height <= 1)
		return ;
	if (stack_b->stack[0] > stack_b->stack[1])
		sb_wrapper(stack_b->stack, stack_b->height);
}

static void	sort_3_a(t_stack *stack_a)
{
	if (stack_a->height <= 2)
	{
		sort_2_a(stack_a);
		return ;
	}
	if (stack_a->stack[0] > stack_a->stack[1]
		&& stack_a->stack[2] > stack_a->stack[1]
		&& stack_a->stack[0] > stack_a->stack[2])
	{
		ra_wrapper(stack_a->stack, stack_a->height);
		return ;
	}
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
	if (stack_a->stack[1] > stack_a->stack[2])
		rra_wrapper(stack_a->stack, stack_a->height);
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
}

static void	sort_3_b(t_stack *stack_b)
{
	if (stack_b->height <= 2)
	{
		sort_2_b(stack_b);
		return ;
	}
	if (stack_b->stack[0] < stack_b->stack[1]
		&& stack_b->stack[1] < stack_b->stack[2])
		return ;
	if (stack_b->stack[0] > stack_b->stack[1]
		&& stack_b->stack[2] > stack_b->stack[1]
		&& stack_b->stack[0] > stack_b->stack[2])
	{
		rb_wrapper(stack_b->stack, stack_b->height);
		return ;
	}
	if (stack_b->stack[0] > stack_b->stack[1])
		sb_wrapper(stack_b->stack, stack_b->height);
	if (stack_b->stack[1] > stack_b->stack[2])
		rrb_wrapper(stack_b->stack, stack_b->height);
	if (stack_b->stack[0] > stack_b->stack[1])
		sb_wrapper(stack_b->stack, stack_b->height);
}

void	sort_6(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	if (stack_a->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	if (stack_a->height > 3)
		pb_wrapper(stack_a->stack, stack_b->stack,
			&stack_a->height, &stack_b->height);
	sort_3_a(stack_a);
	printf("stack a after sort_3_a: ");
	for (int i = 0; i < stack_a->height; i++)
	{
		printf("%d ", stack_a->stack[i]);
	}
	printf("\n");
	sort_3_b(stack_b);
	printf("\nstack b after sort_3_b: ");
	for (int i = 0; i < stack_b->height; i++)
	{
		printf("%d ", stack_b->stack[i]);
	}
	printf("\n--------------\n");
	if (stack_b->height > 0)
		merge_to_a(stack_a, stack_b);
}
