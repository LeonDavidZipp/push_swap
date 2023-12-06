/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/06 13:31:27 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Shifts all elements of st_b up by one
/// @param st_b stack b
/// @param h_b height of stack b
void	rrb(int *st_b, int h_b)
{
	int		temp;

	if (h_b <= 1)
		return ;
	temp = st_b[h_b - 1];
	ft_memmove(&st_b[1], st_b, (size_t)(h_b - 1) * sizeof(int));
	st_b[0] = temp;
}

/// @brief wrapper for rrb writing "rrb\n" to stdout
/// @param st_b stack b
/// @param h_b height of stack b
void	rrb_wrapper(int *st_b, int h_b)
{
	rrb(st_b, h_b);
	write(1, "rrb\n", 4);
}
