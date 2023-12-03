/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:51:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/03 02:34:51 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_sort_int_tab(int *tab, int h)
{
	int	*result;
	int	temp;
	int	i;
	int	not_sorted;

	not_sorted = 1;
	result = ft_calloc(h, sizeof(int));
	result = ft_memmove(result, tab, h);
	while (not_sorted == 1)
	{
		i = -1;
		not_sorted = 0;
		while (++i < h - 1)
		{
			if (result[i] > result[i + 1])
			{
				temp = result[i];
				result[i] = result[i + 1];
				result[i + 1] = temp;
				not_sorted = 1;
			}
		}
	}
	return (result);
}

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

static int	ft_get_index(int *tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i] != nb)
		i++;
	return (i);
}

void	k_sort1(t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	range;
	int	*sorted;

	i = 0;
	range = ft_sqrt(st_a->h) * 14 / 10;
	sorted = ft_sort_int_tab(st_a->st, st_a->h);
	while (st_a->h > 0)
	{
		if (ft_get_index(st_a->st, st_a->st[0]) <= i)
		{
			pb_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
			rb_wrapper(st_b->st, st_b->h);
			i++;
		}
		else if (ft_get_index(st_a->st, st_a->st[0]) <= i + range)
		{
			pb_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
			i++;
		}
		else
			ra_wrapper(st_a->st, st_a->h);
	}
}

void	k_sort2(t_stack *st_a, t_stack *st_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		// rb_count = count_r(stack_b->head, length - 1);
		// rrb_count = (length + 3) - rb_count;
		rb_count = count_rotate(st_b, st_b->st[length - 1]);
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
