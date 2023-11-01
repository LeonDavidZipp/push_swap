/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:30:33 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(int *stack_b, int height_b)
{
	int		temp;

	if (height_b <= 1)
		return ;
	temp = stack_b[height_b - 1];
	ft_memmove(&stack_b[1], stack_b, (size_t)(height_b - 1) * sizeof(int));
	stack_b[0] = temp;
}

void	rb_wrapper(int *stack_b, int *height_b)
{
	rb(stack_b, *height_b);
	write(1, "rb\n", 3);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int stack_b[6] = {1, 2, 3, 4, 5, 6};
// 	int height_b = 6;
// 	rb(stack_b, height_b);
// 	rb(stack_b, height_b);
// 	rb(stack_b, height_b);
// 	printf("pa worked\n");
// 	printf("height_b: %d\n", height_b);
// 	printf("stack_b: %d, %d, %d, %d, %d, %d\n", stack_b[0], stack_b[1],
// stack_b[2], stack_b[3], stack_b[4], stack_b[5]);
// 	return (0);
// }
