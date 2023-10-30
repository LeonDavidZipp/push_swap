/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 13:24:37 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int stack_a[], int height_a)
{
	int			temp;

	if (height_a <= 1)
		return ;
	temp = stack_a[height_a - 1];
	ft_memmove(&stack_a[1], stack_a, (size_t)(height_a - 1) * sizeof(int));
	stack_a[0] = temp;
}
// #include <stdio.h>
// int	main(void)
// {
// 	int stack_a[6] = {1, 2, 3, 4, 5, 6};
// 	int height_a = 6;
// 	ra(stack_a, height_a);
// 	ra(stack_a, height_a);
// 	ra(stack_a, height_a);
// 	printf("pa worked\n");
// 	printf("height_a: %d\n", height_a);
// 	printf("stack_a: %d, %d, %d, %d, %d, %d\n", stack_a[0], stack_a[1],
// stack_a[2], stack_a[3], stack_a[4], stack_a[5]);
// 	return (0);
// }
