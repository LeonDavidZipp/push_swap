/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:01:12 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 16:30:24 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->height <= 1)
		return (stack_a);
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
	return (stack_a);
}
