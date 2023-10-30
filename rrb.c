/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:46 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 13:29:28 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int stack_b[], int height_b)
{
	int			temp;

	if (height_b <= 1)
		return ;
	temp = stack_b[0];
	ft_memmove(stack_b, &stack_b[1], (size_t)(height_b - 1) * sizeof(int));
	stack_b[height_b - 1] = temp;
}
// #include <stdio.h>
// int	main(void)
// {
// 	int stack_b[6] = {1, 2, 3, 4, 5, 6};
// 	int height_b = 6;
// 	ra(stack_b, height_b);
// 	ra(stack_b, height_b);
// 	ra(stack_b, height_b);
// 	printf("pa worked\n");
// 	printf("height_b: %d\n", height_b);
// 	printf("stack_b: %d, %d, %d, %d, %d, %d\n", stack_b[0], stack_b[1],
// stack_b[2], stack_b[3], stack_b[4], stack_b[5]);
// 	return (0);
// }
