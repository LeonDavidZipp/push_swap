/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:19:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/05 17:16:20 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// printf("running!\n");
	if (argc < 2)
		return (0);
	// printf("running 2!\n");
	stack_a = make_stack_a(argc, argv);
	// printf("stack a after creation an height: %d\n", stack_a->height);
	// for (int i = 0; i < stack_a->height; i++)
	// {
	// 	printf("%d ", stack_a->stack[i]);
	// }
	// printf("\n");
	if (!stack_a)
		return (0);
		// printf("running 3!\n");
	stack_b = make_stack_b(*stack_a);
	// printf("height of stack b after creation: %d\n", stack_b->height);
	if (!stack_b)
		return (0);
	sort(stack_a, stack_b);
	// printf("stack a and height: %d \n", stack_a->height);
	// for (int i = 0; i < stack_a->height; i++)
	// {
	// 	printf("%d ", stack_a->stack[i]);
	// }
	// printf("\n");
	// printf("stack b: ");
	// for (int i = 0; i < stack_b->height; i++)
	// {
	// 	printf("%d ", stack_b->stack[i]);
	// }
	// printf("\n");
	return (0);
}
