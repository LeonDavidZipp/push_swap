/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:23:40 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_2_a(t_stack *st_a)
{
	if (st_a->height <= 1)
		return ;
	if (st_a->stack[0] > st_a->stack[1])
		sa_wrapper(st_a->stack, st_a->height);
}

static void	sort_2_b(t_stack *st_b)
{
	if (st_b->height <= 1)
		return ;
	if (st_b->stack[0] > st_b->stack[1])
		sb_wrapper(st_b->stack, st_b->height);
}

static void	sort_3_a(t_stack *st_a)
{
	if (st_a->height <= 2)
	{
		sort_2_a(st_a);
		return ;
	}
	if (st_a->stack[0] > st_a->stack[1]
		&& st_a->stack[2] > st_a->stack[1]
		&& st_a->stack[0] > st_a->stack[2])
	{
		ra_wrapper(st_a->stack, st_a->height);
		return ;
	}
	if (st_a->stack[0] > st_a->stack[1])
		sa_wrapper(st_a->stack, st_a->height);
	if (st_a->stack[1] > st_a->stack[2])
		rra_wrapper(st_a->stack, st_a->height);
	if (st_a->stack[0] > st_a->stack[1])
		sa_wrapper(st_a->stack, st_a->height);
}

static void	sort_3_b(t_stack *st_b)
{
	if (st_b->height <= 2)
	{
		sort_2_b(st_b);
		return ;
	}
	if (st_b->stack[0] < st_b->stack[1]
		&& st_b->stack[1] < st_b->stack[2])
		return ;
	if (st_b->stack[0] > st_b->stack[1]
		&& st_b->stack[2] > st_b->stack[1]
		&& st_b->stack[0] > st_b->stack[2])
	{
		rb_wrapper(st_b->stack, st_b->height);
		return ;
	}
	if (st_b->stack[0] > st_b->stack[1])
		sb_wrapper(st_b->stack, st_b->height);
	if (st_b->stack[1] > st_b->stack[2])
		rrb_wrapper(st_b->stack, st_b->height);
	if (st_b->stack[0] > st_b->stack[1])
		sb_wrapper(st_b->stack, st_b->height);
}

/// @brief Sorts 6 or less elements
/// @param st_a stack a struct
/// @param st_b stack b struct
void	sort_6(t_stack *st_a, t_stack *st_b)
{
	if (st_a->height > 3)
		pb_wrapper(st_a->stack, st_b->stack,
			&st_a->height, &st_b->height);
	if (st_a->height > 3)
		pb_wrapper(st_a->stack, st_b->stack,
			&st_a->height, &st_b->height);
	if (st_a->height > 3)
		pb_wrapper(st_a->stack, st_b->stack,
			&st_a->height, &st_b->height);
	sort_3_a(st_a);
	printf("stack a after sort_3_a: ");
	for (int i = 0; i < st_a->height; i++)
	{
		printf("%d ", st_a->stack[i]);
	}
	printf("\n");
	sort_3_b(st_b);
	printf("\nstack b after sort_3_b: ");
	for (int i = 0; i < st_b->height; i++)
	{
		printf("%d ", st_b->stack[i]);
	}
	printf("\n--------------\n");
	if (st_b->height > 0)
		merge_to_a(st_a, st_b);
}
