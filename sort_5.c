/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/02 17:33:05 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static void	pa_ra_wrapper(int *st_a, int *st_b, int *h_a, int *h_b)
// {
// 	pa_wrapper(st_a, st_b, h_a, h_b);
// 	ra_wrapper(st_a, *h_a);
// }

// static void	rra_pa_ra_ra_wrapper(int *st_a, int *st_b, int *h_a, int *h_b)
// {
// 	rra_wrapper(st_a, *h_a);
// 	pa_ra_wrapper(st_a, st_b, h_a, h_b);
// 	ra_wrapper(st_a, *h_a);
// }

static void	sort_3(t_stack *st_a)
{
	if (st_a->h <= 2)
	{
		if (st_a->h <= 1)
			return ;
		if (st_a->st[0] > st_a->st[1])
			sa_wrapper(st_a->st, st_a->h);
		return ;
	}
	if (st_a->st[0] > st_a->st[1]
		&& st_a->st[2] > st_a->st[1]
		&& st_a->st[0] > st_a->st[2])
	{
		ra_wrapper(st_a->st, st_a->h);
		return ;
	}
	if (st_a->st[0] > st_a->st[1])
		sa_wrapper(st_a->st, st_a->h);
	if (st_a->st[1] > st_a->st[2])
		rra_wrapper(st_a->st, st_a->h);
	if (st_a->st[0] > st_a->st[1])
		sa_wrapper(st_a->st, st_a->h);
}

// static void	sort_4(t_stack *st_a, t_stack *st_b)
// {
// 	if (st_a->h <= 3)
// 	{
// 		sort_3(st_a);
// 		return ;
// 	}
// 	pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 	sort_3(st_a);
// 	if (st_b->st[0] < st_a->st[0])
// 		pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 	else if (st_b->st[0] > st_a->st[st_a->h - 1])
// 		pa_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 	else if (st_b->st[0] > st_a->st[0] && st_b->st[0] < st_a->st[1])
// 	{
// 		ra_wrapper(st_a->st, st_a->h);
// 		pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 		rra_wrapper(st_a->st, st_a->h);
// 	}
// 	else
// 	{
// 		rra_wrapper(st_a->st, st_a->h);
// 		pa_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 		ra_wrapper(st_a->st, st_a->h);
// 	}
// }

/// @brief Sorts 5 or less elements
/// @param st_a stack a struct
/// @param st_b stack b struct
void	sort_7(t_stack *st_a, t_stack *st_b)
{
	int	min_el;
	int	i;
	int	n;

	i = 0;
	n = st_a->h;
	while (i++ < n - 3)
	{
		min_el = smallest_element_a(st_a);
		if (count_rotate(st_a, min_el) < count_reverse_rotate(st_a, min_el))
			while (st_a->st[0] != min_el)
				ra_wrapper(st_a->st, st_a->h);
		else
			while (st_a->st[0] != min_el)
				rra_wrapper(st_a->st, st_a->h);
		if (is_sorted(st_a) && st_b->h == 0)
			return ;
		pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	}
	sort_3(st_a);
	i = 0;
	while (i++ < n - 3)
		pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
}

static int	smallest_element(t_stack *st)
{
	int	i;
	int	min;

	i = -1;
	min = st->st[0];
	while (++i < st->h)
	{
		if (st->st[i] < min)
			min = st->st[i];
	}
	return (min);
}

static int	count_rotate(t_stack *st, int min_el)
{
	int	count;

	count = 0;
	while (st->st[count] != min_el)
		count++;
	return (count);
}

static int	count_reverse_rotate(t_stack *st, int min_el)
{
	int	i;
	int	count;

	i = st->h - 1;
	count = 0;
	while (st->st[i--] != min_el)
		count++;
	return (count);
}
