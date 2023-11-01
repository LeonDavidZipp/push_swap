/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:45:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:28:33 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *stack_a, int *stack_b, int height_a, int height_b)
{
	sa(stack_a, height_a);
	sb(stack_b, height_b);
	ft_printf("ss\n");
}
