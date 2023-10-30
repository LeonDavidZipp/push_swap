/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 01:57:52 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int *stack_a, int *stack_b, int height_a, int height_b)
{
	if (height_b <= 0)
		return ;
	ft_memmove(stack_a, stack_a + 1, (size_t)height_a);
	stack_a[0] = stack_b[0];
	ft_memmove(stack_b + 1, stack_b, (size_t)height_b - 1);
	ft_bzero(stack_b + 1);
}
