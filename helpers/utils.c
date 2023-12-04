/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:45:19 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:44:32 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *st)
{
	int	i;

	i = -1;
	while (++i < st->h - 1)
	{
		if (st->st[i] > st->st[i + 1])
			return (0);
	}
	return (1);
}

int	smallest_element(t_stack *st)
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

int	get_index(int *tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i] != nb)
		i++;
	return (i);
}

int	count_rotate(t_stack *st, int el)
{
	int	count;

	count = 0;
	while (st->st[count] != el)
		count++;
	return (count);
}

int	count_reverse_rotate(t_stack *st, int el)
{
	int	i;
	int	count;

	i = st->h - 1;
	count = 0;
	while (st->st[i--] != el)
		count++;
	return (count);
}
