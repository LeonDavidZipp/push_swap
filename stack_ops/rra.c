/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/06 13:31:17 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Shift down all elements of stack a by 1.
/// The last element becomes the first one
/// @param st_a stack a
/// @param h_a height of stack a
void	rra(int *st_a, int h_a)
{
	int		temp;

	if (h_a <= 1)
		return ;
	temp = st_a[h_a - 1];
	ft_memmove(&st_a[1], st_a, (size_t)(h_a - 1) * sizeof(int));
	st_a[0] = temp;
}

/// @brief wrapper for rra writing "rra\n" to stdout
/// @param st_a stack a
/// @param h_a height of stack a
void	rra_wrapper(int *st_a, int h_a)
{
	rra(st_a, h_a);
	write(1, "rra\n", 4);
}
