/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_runs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:30:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 20:28:11 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/// @brief Counts the number of runs in stack_a.
/// A run is a sequence of numbers that are in ascending order.
/// @param stack_a 
/// @return 
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
		else if (stack_flag == -1)
		{
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
			rrb_wrapper(stack_b->stack, stack_b->height);
		}
	}
	if (stack_a->stack[0] > stack_a->stack[1])
	{
		if (stack_flag == 1)
			ra_wrapper(stack_a->stack, stack_a->height);
		else if (stack_flag == -1)
		{
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
			rrb_wrapper(stack_b->stack, stack_b->height);
		}
	}
}

/// @brief Distributes the runs evenly between stack_a and stack_b.
/// @param stack_a 
/// @param stack_b 
int	distribute_runs(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_flag;
	int		runs_a;
	int		runs_b;

	while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
		ra_wrapper(stack_a->stack, stack_a->height);
	stack_flag = -1;
	runs_a = count_runs(stack_a->stack, stack_a->height);
	// printf("%d\n", runs_a);
	runs_b = 0;
	// while (runs_a != runs_b && runs_a != runs_b + 1 && runs_a != runs_b - 1)
	while (1)
	{
		if (move_run(stack_a, stack_b, stack_flag) == 1)
			return (1);
		if (runs_a == runs_b || runs_a == runs_b + 1 || runs_a == runs_b - 1)
			break ;
		runs_a--;
		runs_b++;
		stack_flag *= -1;
		printf("runs_a: %d\n", runs_a);
		printf("runs_b: %d\n", runs_b);
		printf("stack_flag: %d\n", stack_flag);
		// if (runs_a == runs_b || runs_a == runs_b + 1 || runs_a == runs_b - 1)
		// 	break ;
	}
	return (0);
}

#include "push_swap.h"
#include <stdio.h>

int main()
{
	t_stack *stack_a = (t_stack *)malloc(sizeof(t_stack));
	t_stack *stack_b = (t_stack *)malloc(sizeof(t_stack));

	// Initialize the stacks
	stack_a->height = 8;
	stack_a->stack = (int *)malloc(stack_a->height * sizeof(int));
	stack_b->height = 0;
	stack_b->stack = (int *)malloc(stack_a->height * sizeof(int));
	// Fill stack_a with some values
	stack_a->stack[0] = 6;
	stack_a->stack[1] = 7;
	stack_a->stack[2] = 10;
	stack_a->stack[3] = 12;
	stack_a->stack[4] = 1;
	stack_a->stack[5] = 0;
	stack_a->stack[6] = -1;
	stack_a->stack[7] = -2;

	// Call distribute_runs
	distribute_runs(stack_a, stack_b);
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
	free(stack_a->stack);
	free(stack_b->stack);
	free(stack_a);
	free(stack_b);
	return 0;
}
// cc bubblesort.c sa.c make_stack_a.c make_stack_b.c ft_atoi.c ft_calloc.c ft_isdigit.c ft_split.c ft_strcmp.c ft_strdup.c ft_strsepjoin.c ft_strlen.c ft_substr.c 
// Stack A: 1 0 -1 -2 6 7 10 12 	