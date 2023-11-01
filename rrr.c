/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:25:25 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:54:06 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Shift down all elements of stack_a & stack_b by 1.
/// @param stack_a 
/// @param stack_b 
/// @param height_a 
/// @param height_b 
void	rrr(int stack_a, int stack_b, int height_a, int height_b)
{
	rra(stack_a, height_a);
	rrb(stack_b, height_b);
}

void	rrr_wrapper(int *stack_a, int *stack_b, int height_a, int height_b)
{
	rrr(stack_a, stack_b, height_a, height_b);
	write(1, "rrr\n", 4);
}
