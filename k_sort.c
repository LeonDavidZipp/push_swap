/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:51:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/02 17:54:24 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k_sort1(t_stack *st_a, t_stack *st_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (st_a->h > 0)
	{
		if (st_a->head->s_index <= i)
		{
			pb_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
			rotate(stack_b, 'b', true);
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			pb_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
			i++;
		}
		else
			ra_wrapper(stack_a->st, stack_a->h);
	}
}

void	k_sort2(t_stack *st_a, t_stack *st_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != length - 1)
				rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			length--;
		}
		else
		{
			while (stack_b->head->s_index != length - 1)
				reverse_rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			length--;
		}
	}
}