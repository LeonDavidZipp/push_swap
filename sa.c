/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:32:14 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:24:37 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Swaps the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param st_a stack a
/// @param h_a height of stack a
void	sa(int *st_a, int h_a)
{
	int		temp;

	if (h_a <= 1)
		return ;
	if (st_a[0] > st_a[1])
	{
		temp = st_a[0];
		st_a[0] = st_a[1];
		st_a[1] = temp;
	}
}

/// @brief wrapper for sa writing "sa\n" to stdout
/// @param st_a stack a
/// @param h_a height of stack a
void	sa_wrapper(int *st_a, int h_a)
{
	sa(st_a, h_a);
	write(1, "sa\n", 3);
}
// #include <stdio.h>
// int main() {
//     // Create an array for testing
//     int st_a[] = {3, 1, 2, 4};
//     unsigned int height = 4;

//     printf("Original Array: ");
//     for (unsigned int i = 0; i < height; i++) {
//         printf("%d ", st_a[i]);
//     }
//     printf("\n");

//     // Apply the sa function
//     sa(st_a, height);

//     printf("After sa function: ");
//     for (unsigned int i = 0; i < height; i++) {
//         printf("%d ", st_a[i]);
//     }
//     printf("\n");

//     // Check if the sa function worked
//     if (st_a[0] < st_a[1]) {
//         printf("Test Passed: Elements swapped correctly.\n");
//     } else {
//         printf("Test Failed: Elements not swapped correctly.\n");
//     }

//     return 0;
// }
