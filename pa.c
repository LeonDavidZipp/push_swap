/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:36:35 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Pushes the top element of stack_b to stack_a
/// @param stack_a 
/// @param stack_b 
/// @param height_a 
/// @param height_b 
void	pa(int *stack_a, int *stack_b, int *height_a, int *height_b)
{
	if (*height_b <= 0)
		return ;
	ft_memmove(&stack_a[1], stack_a, (size_t)(*height_a) * sizeof(int));
	stack_a[0] = stack_b[0];
	ft_memmove(stack_b, &stack_b[1], (size_t)(*height_b) * sizeof(int));
	stack_b[*height_b - 1] = 0;
	(*height_a)++;
	(*height_b)--;
	write(1, "pa\n", 3);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int stack_a[6] = {1, 2, 3, 4, 5, 0};
// 	int stack_b[6] = {7, 0, 0, 0, 0, 0};
// 	int height_a = 5;
// 	int height_b = 1;

// 	pa(stack_a, stack_b, &height_a, &height_b);
// 	printf("pa worked\n");
// 	printf("height_a: %d\n", height_a);
// 	printf("height_b: %d\n", height_b);
// 	printf("stack_a: %d, %d, %d, %d, %d, %d\n", stack_a[0], stack_a[1],
// stack_a[2], stack_a[3], stack_a[4], stack_a[5]);
// 	printf("stack_b: %d, %d, %d, %d, %d, %d\n", stack_b[0], stack_b[1],
// stack_b[2], stack_b[3], stack_b[4], stack_b[5]);
// 	return (0);
// }
