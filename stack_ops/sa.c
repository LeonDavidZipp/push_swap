/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:32:14 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/05 11:21:50 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Swaps the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param st_a stack a
/// @param h_a height of stack a
void	sa(int *st_a, int h_a)
{
	int		temp;

	if (h_a <= 1)
		return ;
	temp = st_a[0];
	st_a[0] = st_a[1];
	st_a[1] = temp;
}

/// @brief wrapper for sa writing "sa\n" to stdout
/// @param st_a stack a
/// @param h_a height of stack a
void	sa_wrapper(int *st_a, int h_a)
{
	sa(st_a, h_a);
	write(1, "sa\n", 3);
}
