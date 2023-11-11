/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:45:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:22:38 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Swaps the first 2 elements at the top of stack a and b.
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param h_b height of stack b
void	ss(int *st_a, int *st_b, int h_a, int h_b)
{
	sa(st_a, h_a);
	sb(st_b, h_b);
}

/// @brief wrapper for ss writing "ss\n" to stdout
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param h_b height of stack b
void	ss_wrapper(int *st_a, int *st_b, int h_a, int h_b)
{
	ss(st_a, st_b, h_a, h_b);
	write(1, "ss\n", 3);
}
