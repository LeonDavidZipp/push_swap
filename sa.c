/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:32:14 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 01:43:30 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Swap the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param el1
/// @param el2
void	sa(int *stack_a, unsigned int height)
{
	int				temp;

	if (height <= 1)
		return ;
	if (stack_a[0] > stack_a[1])
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
}
