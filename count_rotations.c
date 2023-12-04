/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:48:41 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:06:47 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
