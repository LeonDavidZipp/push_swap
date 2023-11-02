/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_runs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:30:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 14:15:01 by lzipp            ###   ########.fr       */
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
	count = 0;
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
	int		temp;
	int		sorted;
	int		i;
	int		height;

	temp = stack_a->stack[0];
	sorted = 1;
	i = 1;
	height = stack_a->height;
	printf("temp before loop: %i\n", temp);
	printf("stack1 before loop: %i\n", stack_a->stack[1]);
	while (sorted == 1 && i <= height) //temp < stack_a->stack[1])
	{
		if (stack_flag == 1)
			ra_wrapper(stack_a->stack, stack_a->height);
		else if (stack_flag == -1)
		{
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
			rb_wrapper(stack_b->stack, stack_b->height);
		}
		temp = stack_a->stack[0];
		printf("temp during loop: %i\n", temp);
		printf("stack1 during loop: %i\n", stack_a->stack[1]);
		if (temp > stack_a->stack[1])
			sorted = 0;
	}
	return (i);
}

/// @brief Distributes the runs evenly between stack_a and stack_b.
/// @param stack_a 
/// @param stack_b 
void	distribute_runs(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_flag;
	int		runs_a;
	// int		runs_b;
	int		runs_left;

	while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
		ra_wrapper(stack_a->stack, stack_a->height);
	stack_flag = 1;
	runs_a = count_runs(stack_a->stack, stack_a->height);
	printf("runs_a: %d\n", runs_a);
	// runs_b = 0;
	runs_left = runs_a;
	while (runs_left > 0)// runs_a != runs_b && runs_a != runs_b + 1 && runs_a != runs_b - 1)
	{
		move_run(stack_a, stack_b, stack_flag);
		printf("run moved\n");
		// runs_a--;
		// runs_b++;
		runs_left--;
		stack_flag *= -1;
		// printf("runs_a: %d\n", runs_a);
		// printf("runs_b: %d\n", runs_b);
		// printf("stack_flag: %d\n", stack_flag);
	}
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