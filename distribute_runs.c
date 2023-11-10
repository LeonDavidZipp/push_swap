/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_runs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:30:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/10 10:35:20 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Checks whether stack_a is sorted & thus skips unnecessary steps.
/// @param stack 
/// @param height 
/// @return 1 if sorted, 0 if not sorted.
// static int	is_sorted(int *stack, int height)
// {
// 	int		i;

// 	i = -1;
// 	while (++i < height - 1)
// 	{
// 		if (stack[i] > stack[i + 1])
// 			return (0);
// 	}
// 	return (1);
// }

/// @brief Counts the number of runs in stack_a.
/// A run is a sequence of numbers that are in ascending order.
/// @param stack_a 
/// @return number of runs in stack_a.
static int	count_runs(int *stack, int height)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (i < height - 1)
	{
		if (stack[i] > stack[i + 1])
			count++;
		i++;
	}
	return (count);
}

/// @brief Moves a run to the bottom of stack_a or stack_b.
/// @param stack_a 
/// @param stack_b 
/// @param stack_flag Determines whether the run is moved to stack_a or stack_b.
static void	move_run(t_stack *stack_a, t_stack *stack_b, int stack_flag)
{
	while (stack_a->stack[0] < stack_a->stack[1])
	{
		if (stack_flag == 1)
			ra_wrapper(stack_a->stack, stack_a->height);
		else
		{
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
			// if (stack_b->height > 1)
			// 	rb_wrapper(stack_b->stack, stack_b->height);
		}
	}
	if (stack_a->stack[0] > stack_a->stack[1])
	{
		if (stack_flag == 1)
			ra_wrapper(stack_a->stack, stack_a->height);
		else
		{
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
			// if (stack_b->height > 1)
			// 	rb_wrapper(stack_b->stack, stack_b->height);
		}
	}
}

/// @brief Distributes the runs evenly between stack_a and stack_b.
/// @param stack_a 
/// @param stack_b 
/// @return 1 if sorted, 0 if not sorted.
int	distribute_runs(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_flag;
	int		runs_a;
	int		runs_b;

	while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
		ra_wrapper(stack_a->stack, stack_a->height);
	// if (is_sorted(stack_a->stack, stack_a->height) == 1)
	// 	return (-1);
	stack_flag = 1;
	runs_a = count_runs(stack_a->stack, stack_a->height);
	if (runs_a == 1)
		return (-1);
	runs_b = 0;

	while (runs_a != runs_b && runs_a  != runs_b + 1 && runs_a != runs_b - 1)
	{
		move_run(stack_a, stack_b, stack_flag);
		if (stack_flag == -1)
		{
			runs_a--;
			runs_b++;
		}
		stack_flag *= -1;
	}
	return (runs_a + runs_b);
}

#include "push_swap.h"
#include <stdio.h>
int main()
{
	t_stack *stack_a = (t_stack *)malloc(sizeof(t_stack));
	t_stack *stack_b = (t_stack *)malloc(sizeof(t_stack));
	// Initialize the stacks
	int stacka[50] = {11, 2, 3, 4, 99, 6, 7, 8, 9, -300, 12, 13, 14, 15, 16, 17, 18, 19, 60000, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 900, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53};
	stack_a->stack = stacka;
	stack_a->height = 50;
	int stackb[50] = {0};
	stack_b->stack = stackb;
	stack_b->height = 0;
	// Call distribute_runs
	int sorted = distribute_runs(stack_a, stack_b);
	sorted += 1;
	// while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
	// 	ra_wrapper(stack_a->stack, stack_a->height);
	// printf("runs: %d\n", count_runs(stack_a->stack, stack_a->height));

	// Print the results
	printf("Stack A: ");
	for (int i = 0; i < stack_a->height; i++)
	{
		printf("%d ", stack_a->stack[i]);
	}
	printf("\n");
	printf("Stack B: ");
	for (int i = 0; i < stack_b->height; i++)
	{
		printf("%d ", stack_b->stack[i]);
	}
	printf("\n");
	// Free the stacks
	// free(stack_a->stack);
	// free(stack_b->stack);
	// free(stack_a);
	// free(stack_b);
	return 0;
}
// cc distribute_runs.c ra.c pb.c rb.c ft_memmove.c
