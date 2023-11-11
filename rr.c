/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:25:25 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:21:36 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Shift up all elements of st_a & st_b by 1.
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param h_b height of stack b
void	rr(int *st_a, int *st_b, int h_a, int h_b)
{
	ra(st_a, h_a);
	rb(st_b, h_b);
}

/// @brief wrapper for rr writing "rr\n" to stdout
/// @param st_a 
/// @param st_b 
/// @param h_a 
/// @param h_b 
void	rr_wrapper(int *st_a, int *st_b, int h_a, int h_b)
{
	rr(st_a, st_b, h_a, h_b);
	write(1, "rr\n", 3);
}
