/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/10 22:16:59 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>
/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_flag;
	int		runs;

	printf("\n---------------\ndistributing runs\n");
	runs = distribute_runs(stack_a, stack_b);
	printf("stack a: ");
	for (int i = 0; i < stack_a->height; i++)
	{
		printf("%d ", stack_a->stack[i]);
	}
	printf("\n");
	printf("stack b: ");
	for (int i = 0; i < stack_b->height; i++)
	{
		printf("%d ", stack_b->stack[i]);
	}
	printf("\n");
	// return ;
	if (runs == -1)
		return ;
	if (stack_a->height + stack_b->height <= 6)
	{
		printf("\n---------------\nnow sorting 6 or less\n");
		sort_6(stack_a, stack_b);
		return ;
	}
	stack_flag = 1;
	if (runs % 2 == 1)
		stack_flag = -1;
	printf("\n---------------\nnow sorting\n");
	while (stack_b->height > 0)
	{
		if (stack_flag == 1)
		{
			printf("\n---------------\nmerging to a\n");
			merge_to_a(stack_a, stack_b);
		}
		else
		{
			printf("\n---------------\nmerging to b\n");
			merge_to_b(stack_a, stack_b);
		}
		printf("stack a: ");
		for (int i = 0; i < stack_a->height; i++)
		{
			printf("%d ", stack_a->stack[i]);
		}
		printf("\n");
		printf("stack b: ");
		for (int i = 0; i < stack_b->height; i++)
		{
			printf("%d ", stack_b->stack[i]);
		}
		printf("\n");
		stack_flag *= -1;
		break ;
	}
	printf("\n---------------\ndone\n");
}
// #include "push_swap.h"
// #include <stdio.h>
// int main(void)
// {
//     t_stack stack_a;
//     t_stack stack_b;
//     // Initialize the heights of the stacks
//     // Allocate memory for the stacks
// 	// int stacka[50] = {11, 2, 3, 4, 99, 6, 7, 8, 9, -300, 12, 13, 14, 15, 16, 17, 18, 19, 60000, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 900, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53};
//     int stacka[5] = {4, 67, 3, 87, 23};
// 	stack_a.stack = stacka;
//     // stack_a.height = 50;
// 	stack_a.height = 5;
//     int stackb[5] = {0};
//     stack_b.stack = stackb;
//     stack_b.height = 0;
//     // Sort stack_a using stack_b as a temporary stack
// 	printf("stack before sorting: \n");
// 	printf("stack a: ");
//     for (int i = 0; i < stack_a.height; i++)
//     {
//         printf("%d ", stack_a.stack[i]);
//     }
//     printf("\n");
// 	printf("stack b: ");
//     for (int i = 0; i < stack_b.height; i++)
//     {
//         printf("%d ", stack_b.stack[i]);
//     }
//     printf("\n");
//     sort(&stack_a, &stack_b);
//     // Print the sorted numbers
//     return 0;
// }
// cc sort.c pb.c rb.c ft_memmove.c sort_3.c sort_2.c distribute_runs.c ra.c rra.c rrb.c sa.c sb.c pa.c
