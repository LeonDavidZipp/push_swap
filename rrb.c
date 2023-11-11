/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:26:00 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Shifts all elements of st_b up by one
/// @param st_b stack b
/// @param h_b height of stack b
void	rrb(int *st_b, int h_b)
{
	int		temp;

	if (h_b <= 1)
		return ;
	temp = st_b[h_b - 1];
	ft_memmove(&st_b[1], st_b, (size_t)(h_b - 1) * sizeof(int));
	st_b[0] = temp;
}

/// @brief wrapper for rrb writing "rrb\n" to stdout
/// @param st_b stack b
/// @param h_b height of stack b
void	rrb_wrapper(int *st_b, int h_b)
{
	rrb(st_b, h_b);
	write(1, "rrb\n", 4);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int st_b[6] = {1, 2, 3, 4, 5, 6};
// 	int h_b = 6;
// 	ra(st_b, h_b);
// 	ra(st_b, h_b);
// 	ra(st_b, h_b);
// 	printf("pa worked\n");
// 	printf("h_b: %d\n", h_b);
// 	printf("st_b: %d, %d, %d, %d, %d, %d\n", st_b[0], st_b[1],
// st_b[2], st_b[3], st_b[4], st_b[5]);
// 	return (0);
// }
