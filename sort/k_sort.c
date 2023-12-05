/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:51:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/05 11:43:38 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*sort(int *result, int h)
{
	int	temp;
	int	i;
	int	not_sorted;

	not_sorted = 1;
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

static int	*ft_sort_int_tab(int *tab, int h)
{
	int	*result;
	int	i;

	result = ft_calloc(h, sizeof(int));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < h)
		result[i] = tab[i];
	return (sort(result, h));
}

static void	sort_to_b(t_stack *st_a, t_stack *st_b, int len, int *sorted)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(len) * 14 / 10;
	while (st_a->h > 0)
	{
		if (get_index(sorted, st_a->st[0]) <= i)
		{
			pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
			rb_wrapper(st_b->st, st_b->h);
			i++;
		}
		else if (get_index(sorted, st_a->st[0]) <= i + range)
		{
			pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
			i++;
		}
		else
			ra_wrapper(st_a->st, st_a->h);
	}
}

static void	sort_to_a(t_stack *st_a, t_stack *st_b, int len, int *sorted)
{
	int	rb_count;
	int	rrb_count;

	while (len - 1 >= 0)
	{
		rb_count = count_rotate(st_b, sorted[len - 1]);
		rrb_count = (len + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (get_index(sorted, st_b->st[0]) != len - 1)
			{
				rb_wrapper(st_b->st, st_b->h);
			}
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		}
		else
		{
			while (get_index(sorted, st_b->st[0]) != len -1)
				rrb_wrapper(st_b->st, st_b->h);
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		}
		len--;
	}
}

void	k_sort(t_stack *st_a, t_stack *st_b)
{
	int	len;
	int	*sorted;

	if (is_sorted(st_a))
		return ;
	sorted = ft_sort_int_tab(st_a->st, st_a->h);
	len = st_a->h;
	if (!sorted)
		return ;
	else if (len == 3)
		sort_3(st_a);
	else if (len <= 7)
		sort_7(st_a, st_b);
	else
	{
		sort_to_b(st_a, st_b, len, sorted);
		sort_to_a(st_a, st_b, len, sorted);
		free(sorted);
	}
}
