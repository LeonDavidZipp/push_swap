/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 17:07:02 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Shift up all elements of stack a by 1.
// The first element becomes the last one.
/// @param st_a stack a
/// @param h_a height of stack a
void	ra(int *st_a, int h_a)
{
	int		temp;

	if (h_a <= 1)
		return ;
	temp = st_a[0];
	ft_memmove(st_a, &st_a[1], (size_t)(h_a - 1) * sizeof(int));
	st_a[h_a - 1] = temp;
}

/// @brief wrapper for ra writing "ra\n" to stdout
/// @param st_a stack a
/// @param h_a height of stack a
void	ra_wrapper(int *st_a, int h_a)
{
	ra(st_a, h_a);
	write(1, "ra\n", 3);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int st_a[6] = {1, 2, 3, 4, 5, 6};
// 	int h_a = 6;
// 	ra(st_a, h_a);
// 	// ra(st_a, h_a);
// 	// ra(st_a, h_a);
// 	// printf("pa worked\n");
// 	// printf("h_a: %d\n", h_a);
// 	// printf("st_a: %d, %d, %d, %d, %d, %d\n", st_a[0], st_a[1],
// st_a[2], st_a[3], st_a[4], st_a[5]);
// 	return (0);
// }
