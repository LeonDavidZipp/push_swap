/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:17:37 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// #include <stdio.h>
// int	main(void)
// {
// 	int st_a[6] = {1, 2, 3, 4, 5, 0};
// 	int st_b[6] = {7, 0, 0, 0, 0, 0};
// 	int h_a = 5;
// 	int h_b = 1;

// 	pa(st_a, st_b, &h_a, &h_b);
// 	printf("pa worked\n");
// 	printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
// 	printf("st_a: %d, %d, %d, %d, %d, %d\n", st_a[0], st_a[1],
// st_a[2], st_a[3], st_a[4], st_a[5]);
// 	printf("st_b: %d, %d, %d, %d, %d, %d\n", st_b[0], st_b[1],
// st_b[2], st_b[3], st_b[4], st_b[5]);
// 	return (0);
// }
