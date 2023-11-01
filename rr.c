/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:25:25 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:30:24 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(int *stack_a, int *stack_b, int height_a, int height_b)
{
	ra(stack_a, height_a);
	rb(stack_b, height_b);
	write(1, "rr\n", 3);
}
