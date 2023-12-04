/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:04:22 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:37:44 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Generates stack b from stack a.
/// @param st_a stack a struct
/// @return an empty stack b of same size as stack a
t_stack	*make_stack_b(t_stack *st_a)
{
	t_stack	*st_b;
	int		*stack;

	st_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!st_b)
		return (NULL);
	stack = (int *)ft_calloc(st_a->h, sizeof(int *));
	if (!stack)
		return (NULL);
	st_b->st = stack;
	st_b->h = 0;
	st_b->runs = 0;
	return (st_b);
}
