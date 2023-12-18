/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/18 14:37:20 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}

// #include <stdio.h>
// void print_arrays(int *st_a, int *st_b, int h_a, int h_b) {
//     int i;

//     (void)h_b;
// 	printf("st_a: ");
//     for(i = 0; i < h_a; i++) {
//         printf("%d ", st_a[i]);
//     }
//     printf("\n");

//     printf("st_b: ");
//     for(i = 0; i < 20; i++) {
//         printf("%d ", st_b[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int st_a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int st_b[10] = {0};
//     int h_a = 10;
//     int h_b = 0;

//     print_arrays(st_a, st_b, h_a, h_b);

//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// 	printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
// 	pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// 	printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
// 	pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// 	printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
// 	pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);
//     pb(st_a, st_b, &h_a, &h_b);
//     print_arrays(st_a, st_b, h_a, h_b);
// 	printf("h_a: %d\n", h_a);
// 	printf("h_b: %d\n", h_b);

//     return 0;
// }
