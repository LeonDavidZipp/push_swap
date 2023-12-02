/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:51:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/02 18:43:20 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	rt_up;
	int	rt_down;
	int	max_loop;

	rt_up = nb / 3;
	rt_down = 0;
	max_loop = 46341;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	if (nb == 4)
		return (2);
	while (rt_up >= rt_down && max_loop)
	{
		if (rt_up * rt_up == nb)
			return (rt_up);
		else if (rt_down * rt_down == nb)
			return (rt_down);
		rt_up--;
		rt_down++;
		max_loop--;
	}
	return (0);
}

void	k_sort1(t_stack *st_a, t_stack *st_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (st_a->h > 0)
	{
		if (st_a->head->s_index <= i)
		// if (st_a-st[0])
		{
			pb_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
			rb_wrapper(st_b->st, st_b->h);
			i++;
		}
		else if (st_a->head->s_index <= i + range)
		// else if (st_a->st[0] <= i + range)
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
				rb_wrapper(stack_b->st, stack_b->h);
			pa_wrapper(stack_a->st, stack_b->st, stack_a->h, stack_b->h);
			length--;
		}
		else
		{
			while (st_b->head->s_index != length - 1)
				rrb_wrapper(st_b->st, st_b->h);
			pa_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
			length--;
		}
	}
}
