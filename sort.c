/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 10:54:01 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		runs;

	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	distribute_runs(stack_a, stack_b);
}
