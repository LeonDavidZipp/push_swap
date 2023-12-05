/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:51:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/05 11:53:29 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief helper function of ft_sort_int_tab
/// @param result the array to sort
/// @param h length of the array
/// @return the sorted array
static int	*sort(int *result, int h)
{
	int		temp;
	int		i;
	int		not_sorted;

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

/// @brief sorts an array of integers
/// @param tab the array to sort
/// @param h length of the array
/// @return the sorted array
static int	*ft_sort_int_tab(int *tab, int h)
{
	int		*result;
	int		i;

	result = ft_calloc(h, sizeof(int));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < h)
		result[i] = tab[i];
	return (sort(result, h));
}

/// @brief moves elements from stack a to stack b, the smallest elements are 
/// moved to the middle of stack b, the larger ones are moved to the top and 
/// bottom of stack b
/// @param st_a stack a
/// @param st_b stack b
/// @param len height of stack a
/// @param sorted presorted array of integers to have access to indexes
static void	sort_to_b(t_stack *st_a, t_stack *st_b, int h_a, int *sorted)
{
	int		i;
	int		range;

	i = 0;
	range = ft_sqrt(h_a) * 14 / 10;
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

/// @brief moves elements back from stack b to stack a
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param sorted presorted array of integers to have access to indexes
static void	sort_to_a(t_stack *st_a, t_stack *st_b, int h_a, int *sorted)
{
	int		rb_count;
	int		rrb_count;

	while (h_a - 1 >= 0)
	{
		rb_count = count_rotate(st_b, sorted[h_a - 1]);
		rrb_count = (h_a + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (get_index(sorted, st_b->st[0]) != h_a - 1)
				rb_wrapper(st_b->st, st_b->h);
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		}
		else
		{
			while (get_index(sorted, st_b->st[0]) != h_a -1)
				rrb_wrapper(st_b->st, st_b->h);
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		}
		h_a--;
	}
}

void	k_sort(t_stack *st_a, t_stack *st_b)
{
	int		h_a;
	int		*sorted;

	if (is_sorted(st_a))
		return ;
	sorted = ft_sort_int_tab(st_a->st, st_a->h);
	h_a = st_a->h;
	if (!sorted)
		return ;
	else if (h_a == 3)
		sort_3(st_a);
	else if (h_a <= 7)
		sort_7(st_a, st_b);
	else
	{
		sort_to_b(st_a, st_b, h_a, sorted);
		sort_to_a(st_a, st_b, h_a, sorted);
		free(sorted);
	}
}
