/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/06 13:30:07 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Pushes the top element of st_b to st_a
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param h_b height of stack b
void	pa(int *st_a, int *st_b, int *h_a, int *h_b)
{
	if (*h_b <= 0)
		return ;
	ft_memmove(&st_a[1], st_a, (size_t)(*h_a) * sizeof(int));
	st_a[0] = st_b[0];
	ft_memmove(st_b, &st_b[1], (size_t)(*h_b) * sizeof(int));
	st_b[*h_b - 1] = 0;
	(*h_a)++;
	(*h_b)--;
}

/// @brief Wrapper of pa writing "pa\n" to stdout
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param h_b height of stack b
void	pa_wrapper(int *st_a, int *st_b, int *h_a, int *h_b)
{
	pa(st_a, st_b, h_a, h_b);
	write(1, "pa\n", 3);
}
