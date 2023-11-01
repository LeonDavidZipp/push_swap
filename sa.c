/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:32:14 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:41:29 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Swaps the first 2 elements at the top of stack a.
/// Do nothing if there is only one or no elements.
/// @param el1
/// @param el2
void	sa(int *stack_a, int height_a)
{
	int		temp;

	if (height_a <= 1)
		return ;
	if (stack_a[0] > stack_a[1])
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
}

void	sa_wrapper(int *stack_a, int height_a)
{
	sa(stack_a, height_a);
	write(1, "sa\n", 3);
}
// #include <stdio.h>
// int main() {
//     // Create an array for testing
//     int stack_a[] = {3, 1, 2, 4};
//     unsigned int height = 4;

//     printf("Original Array: ");
//     for (unsigned int i = 0; i < height; i++) {
//         printf("%d ", stack_a[i]);
//     }
//     printf("\n");

//     // Apply the sa function
//     sa(stack_a, height);

//     printf("After sa function: ");
//     for (unsigned int i = 0; i < height; i++) {
//         printf("%d ", stack_a[i]);
//     }
//     printf("\n");

//     // Check if the sa function worked
//     if (stack_a[0] < stack_a[1]) {
//         printf("Test Passed: Elements swapped correctly.\n");
//     } else {
//         printf("Test Failed: Elements not swapped correctly.\n");
//     }

//     return 0;
// }
