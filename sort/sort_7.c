/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:37:44 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *st_a)
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

/// @brief Sorts 7 or less elements
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
		min_el = smallest_element(st_a);
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
