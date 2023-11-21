/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/21 14:09:27 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>
/// @brief Sorts st_a using st_b as a temporary stack.
/// @param st_a stack a struct
/// @param st_b stack b struct
void	sort(t_stack *st_a, t_stack *st_b)
{
	int		stack_flag;

	if (st_a->h <= 5)
	{
		sort_5(st_a, st_b);
		return ;
	}
	if (distribute_runs(st_a, st_b) == -1)
		return ;
	printf("stack a:\n");
	for (int i = 0; i < st_a->h; i++)
	{
		printf("%d ", st_a->st[i]);
	}
	printf("\nstack b:\n");
	for (int i = 0; i < st_b->h; i++)
	{
		printf("%d ", st_b->st[i]);
	}
	printf("\n");
	if (st_a->runs < st_b->runs)
	{
		merge_to_a(st_a, st_b);
		st_b->runs--;
	}
	stack_flag = 1 - 2 * ((st_a->runs + st_b->runs) % 2);
	while (st_b->h > 0)
	{
		if (stack_flag == 1)
		{
			merge_to_a(st_a, st_b);
			st_b->runs--;
		}
		else
		{
			merge_to_b(st_a, st_b);
			st_a->runs--;
		}
		printf("stack a:\n");
		for (int i = 0; i < st_a->h; i++)
		{
			printf("%d ", st_a->st[i]);
		}
		printf("\nstack b:\n");
		for (int i = 0; i < st_b->h; i++)
		{
			printf("%d ", st_b->st[i]);
		}
		printf("\n");
		stack_flag *= -1;
		if (st_a->h <= 0)
		{
			merge_to_a(st_a, st_b);
			stack_flag = 1;
		}
	}
}
// void	sort(t_stack *st_a, t_stack *st_b)
// {
// 	int		stack_flag;
// 	int		runs;

// 	// printf("\n---------------\ndistributing runs\n");
// 	runs = distribute_runs(st_a, st_b);
// 	// printf("stack a: ");
// 	for (int i = 0; i < st_a->h; i++)
// 	{
// 		// printf("%d ", st_a->st[i]);
// 	}
// 	// printf("\n");
// 	// printf("stack b: ");
// 	for (int i = 0; i < st_b->h; i++)
// 	{
// 		// printf("%d ", st_b->st[i]);
// 	}
// 	// printf("\n");
// 	// return ;
// 	if (runs == -1)
// 		return ;
// 	if (st_a->h + st_b->h <= 6)
// 	{
// 		// printf("\n---------------\nnow sorting 6 or less\n");
// 		sort_6(st_a, st_b);
// 		return ;
// 	}
// 	stack_flag = 1;
// 	if (runs % 2 == 1)
// 		stack_flag = -1;
// 	// printf("\n---------------\nnow sorting\n");
// 	while (st_b->h > 0)
// 	{
// 		if (stack_flag == 1)
// 		{
// 			// printf("\n---------------\nmerging to a\n");
// 			merge_to_a(st_a, st_b);
// 		}
// 		else
// 		{
// 			// printf("\n---------------\nmerging to b\n");
// 			merge_to_b(st_a, st_b);
// 		}
// 		// printf("stack a: ");
// 		for (int i = 0; i < st_a->h; i++)
// 		{
// 			// printf("%d ", st_a->st[i]);
// 		}
// 		// printf("\n");
// 		// printf("stack b: ");
// 		for (int i = 0; i < st_b->h; i++)
// 		{
// 			// printf("%d ", st_b->st[i]);
// 		}
// 		// printf("\n");
// 		stack_flag *= -1;
// 		// break ;
// 	}
// 	// printf("\n---------------\ndone\n");
// }
// #include "push_swap.h"
// #include <stdio.h>
// int main(void)
// {
//     t_stack st_a;
//     t_stack st_b;
//     // Initialize the heights of the stacks
//     // Allocate memory for the stacks
// 	// int stacka[50] = {11, 2, 3, 4, 99, 6, 7, 8, 9, -300, 12, 13, 14, 15, 16, 17, 18, 19, 60000, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 900, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53};
//     int stacka[5] = {4, 67, 3, 87, 23};
// 	st_a.stack = stacka;
//     // st_a.height = 50;
// 	st_a.height = 5;
//     int stackb[5] = {0};
//     st_b.stack = stackb;
//     st_b.height = 0;
//     // Sort st_a using st_b as a temporary stack
// 	// printf("stack before sorting: \n");
// 	// printf("stack a: ");
//     for (int i = 0; i < st_a.height; i++)
//     {
//         // printf("%d ", st_a.stack[i]);
//     }
//     // printf("\n");
// 	// printf("stack b: ");
//     for (int i = 0; i < st_b.height; i++)
//     {
//         // printf("%d ", st_b.stack[i]);
//     }
//     // printf("\n");
//     sort(&st_a, &st_b);
//     // Print the sorted numbers
//     return 0;
// }
// cc sort.c pb.c rb.c ft_memmove.c sort_3.c sort_2.c distribute_runs.c ra.c rra.c rrb.c sa.c sb.c pa.c
