/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:27:43 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Pushes the top element of st_a to st_b
/// @param st_a 
/// @param st_b 
/// @param h_a 
/// @param h_b 
void	pb(int *st_a, int *st_b, int *h_a, int *h_b)
{
	if (*h_a <= 0)
		return ;
	ft_memmove(&st_b[1], st_b, (size_t)(*h_b) * sizeof(int));
	st_b[0] = st_a[0];
	ft_memmove(st_a, &st_a[1], (size_t)(*h_a) * sizeof(int));
	st_a[*h_a - 1] = 0;
	(*h_b)++;
	(*h_a)--;
}

/// @brief Wrapper of pb writing "pb\n" to stdout
/// @param st_a stack a
/// @param st_b stack b
/// @param h_a height of stack a
/// @param h_b height of stack b
void	pb_wrapper(int *st_a, int *st_b, int *h_a, int *h_b)
{
	pb(st_a, st_b, h_a, h_b);
	write(1, "pb\n", 3);
	// printf("height b and a after pb wrapper: %d %d\n", *h_a, *h_b);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int st_a[6] = {1, 2, 3, 4, 5, 0};
// 	int st_b[6] = {7, 0, 0, 0, 0, 0};
// 	int h_a = 5;
// 	int h_b = 1;

// 	pb_wrapper(st_a, st_b, &h_a, &h_b);
// 	pb_wrapper(st_a, st_b, &h_a, &h_b);
// 	printf("pa worked\n");
// 	printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
// 	printf("st_a: %d, %d, %d, %d, %d, %d\n", st_a[0], st_a[1],
// st_a[2], st_a[3], st_a[4], st_a[5]);
// 	printf("st_b: %d, %d, %d, %d, %d, %d\n", st_b[0], st_b[1],
// st_b[2], st_b[3], st_b[4], st_b[5]);
// 	return (0);
// }
