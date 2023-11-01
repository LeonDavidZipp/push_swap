/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:32:14 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:28:14 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Swap the first 2 elements at the top of stack b.
/// Do nothing if there is only one or no elements.
/// @param el1
/// @param el2
void	sb(int *stack_b, unsigned int height)
{
	int		temp;

	if (height <= 1)
		return ;
	if (stack_b[0] > stack_b[1])
	{
		temp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp;
	}
}

void	sb_wrapper(int *stack_b, int *height_b)
{
	sb(stack_b, *height_b);
	ft_printf("sb\n");
}