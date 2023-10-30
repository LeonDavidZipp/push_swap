/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:47:38 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 11:01:00 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(int stack_a[], int stack_b[], int *height_a, int *height_b)
{
	if (*height_b <= 0)
		return ;
	stack_a = ft_memmove(&stack_a[1], &stack_a[0], (size_t)(*height_a));
	stack_a[0] = stack_b[0];
	stack_b = ft_memmove(&stack_b[0], &stack_b[1], (size_t)(*height_b));
	ft_bzero(stack_b + *height_b, 1); // questionable
	*height_a += 1;
	*height_b -= 1;
}

#include <stdio.h>
int	main(void)
{
	int stack_a[6] = {1, 2, 3, 4, 5, 0};
	int stack_b[6] = {7, 0, 0, 0, 0, 0};
	int height_a = 5;
	int height_b = 1;

	pa(stack_a, stack_b, &height_a, &height_b);
	printf("pa worked\n");
	printf("stack_a: %d, %d, %d, %d, %d, %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4], stack_a[5]);
	printf("stack_b: %d, %d, %d, %d, %d, %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4], stack_b[5]);
	printf("height_a: %d\n", height_a);
	printf("height_b: %d\n", height_b);
	return (0);
}
