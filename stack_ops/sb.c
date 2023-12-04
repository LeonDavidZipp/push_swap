/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:32:14 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:37:44 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Swaps the first 2 elements at the top of stack b.
/// Do nothing if there is only one or no elements.
/// @param st_b stack b
/// @param h_b height of stack b
void	sb(int *st_b, int h_b)
{
	int		temp;

	if (h_b <= 1)
		return ;
	if (st_b[0] > st_b[1])
	{
		temp = st_b[0];
		st_b[0] = st_b[1];
		st_b[1] = temp;
	}
}

/// @brief wrapper for sb writing "sb\n" to stdout
/// @param st_b stack b
/// @param h_b height of stack b
void	sb_wrapper(int *st_b, int h_b)
{
	sb(st_b, h_b);
	write(1, "sb\n", 3);
}
