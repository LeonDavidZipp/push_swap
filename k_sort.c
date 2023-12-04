/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:51:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:08:23 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int	*ft_sort_int_tab(int *tab, int h)
{
	int	*result;
	int	temp;
	int	i;
	int	not_sorted;

	result = ft_calloc(h, sizeof(int));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < h)
		result[i] = tab[i];
	// printf("height: %d\n", h);
	// for (int i = 0; i < h; i++)
	// 	printf("%d\n", result[i]);
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
	// printf("sorted:\n");
	// for (int i = 0; i < h; i++)
	// 	printf("%d\n", result[i]);
	return (result);
}

static int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 4)
		return (1);
	i = 2;
	while (i * i < nb)
		i++;
	if (i * i > nb)
	{
		if ((i * i - nb) < ((i - 1) * (i - 1) - nb))
			return (i);
	}
	return (i - 1);
}

static void	sort_to_b(t_stack *st_a, t_stack *st_b, int length, int *sorted)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
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

void	sort_to_a(t_stack *st_a, t_stack *st_b, int length, int *sorted)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_rotate(st_b, sorted[length - 1]);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (get_index(sorted, st_b->st[0]) != length - 1)
			{
				rb_wrapper(st_b->st, st_b->h);
			}
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		}
		else
		{
			while (get_index(sorted, st_b->st[0]) != length -1)
				rrb_wrapper(st_b->st, st_b->h);
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		}
		length--;
	}
}
#include <stdio.h>
void	k_sort(t_stack *st_a, t_stack *st_b)
{
	int	length;
	int	*sorted;

	sorted = ft_sort_int_tab(st_a->st, st_a->h);
	if (!sorted)
		return ;
	// for (int i = 0; i < st_a->h; i++)
	// 	printf("%d\n", sorted[i]);
	length = st_a->h;
	if (is_sorted(st_a))
		return ;
	else if (length == 3)
		sort_3(st_a);
	else if (length <= 7)
		sort_7(st_a, st_b);
	else
	{
		sort_to_b(st_a, st_b, length, sorted);
		sort_to_a(st_a, st_b, length, sorted);
		free(sorted);
	}
}
