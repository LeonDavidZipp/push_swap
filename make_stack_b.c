/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:04:22 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 11:48:11 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack_b(t_stack stack_a)
{
	t_stack	*stack_b;
	int		*stack;

	stack_b = (int *)ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	stack = (int *)ft_calloc(stack_a.height, sizeof(int *));
	if (!stack)
		return (NULL);
	stack_b->stack = stack;
	stack_b->height = stack_a.height;
	return (stack_b);
}
