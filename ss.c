/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:45:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:55:16 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *stack_a, int *stack_b, int height_a, int height_b)
{
	sa(stack_a, height_a);
	sb(stack_b, height_b);
}

void	ss_wrapper(int *stack_a, int *stack_b, int height_a, int height_b)
{
	ss(stack_a, stack_b, height_a, height_b);
	write(1, "ss\n", 3);
}
