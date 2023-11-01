/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:04:22 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 11:05:51 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_stack_b(int height_a)
{
	int	*stack_b;

	stack_b = (int *)ft_calloc(height_a, sizeof(int));
	if (!stack_b)
		return (NULL);
	return (stack_b);
}
