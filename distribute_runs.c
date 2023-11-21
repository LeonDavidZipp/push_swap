/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_runs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:30:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/21 12:40:18 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/// @brief Counts the number of runs in st_a.
/// A run is a sequence of numbers that are in ascending order.
/// @param st_a 
/// @return number of runs in st_a.
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

/// @brief Moves a run to the bottom of st_a or st_b.
/// @param st_a 
/// @param st_b 
/// @param stack_flag Determines whether the run is moved to st_a or st_b.
static void	move_run(t_stack *st_a, t_stack *st_b, int stack_flag)
{
	int		temp;

	temp = st_a->st[0];
	while (temp <= st_a->st[0])
	{
		temp = st_a->st[0];
		if (stack_flag == 1)
			ra_wrapper(st_a->st, st_a->h);
		else
		{
			pb_wrapper(st_a->st, st_b->st,
				&(st_a->h), &(st_b->h));
			if (st_b->h > 1)
				rb_wrapper(st_b->st, st_b->h);
		}
	}
}

/// @brief Distributes the runs evenly between st_a and st_b.
/// @param st_a 
/// @param st_b 
/// @return 1 if sorted, 0 if not sorted.
int	distribute_runs(t_stack *st_a, t_stack *st_b)
{
	int		stack_flag;
	int		runs_a;
	int		runs_b;

	while (st_a->st[0] > st_a->st[st_a->h - 1])
		ra_wrapper(st_a->st, st_a->h);
	stack_flag = 1;
	runs_a = count_runs(st_a->st, st_a->h);
	if (runs_a == 1)
		return (-1);
	runs_b = 0;
	while (runs_a != runs_b && runs_a != runs_b + 1 && runs_a != runs_b - 1)
	{
		move_run(st_a, st_b, stack_flag);
		if (stack_flag == -1)
		{
			runs_a--;
			runs_b++;
		}
		stack_flag *= -1;
	}
	st_a->runs = runs_a;
	st_b->runs = runs_b;
	return (runs_a + runs_b);
}

// int	distribute_runs_alternative(t_stack *st_a, t_stack *st_b)
// {
// 	int		height;

// 	height = st_a->h / 2;
// 	while (st_a->h > height)
// 		pb_wrapper(st_a->st, st_b->st, &(st_a->h), &(st_b->h));
// }

// int	sort_alternate(t_stack *st_a, t_stack *st_b)
// {
// 	int		stack_flag;
// 	int		run_len;
// 	int		i;

// 	distribute_runs_alternative(st_a, st_b);
// 	stack_flag = -1;
// 	run_len = 2;
// 	while (st_b->h > 0)
// 	{
// 		i = 0;
// 		while (i < run_len)
// 		{
// 			if (stack_flag == 1) // merge to a
// 			{
// 				;
// 			}
// 			else // merge to b
// 			{
// 				;
// 			}
// 			if (i == run_len - 1)
// 				stack_flag *= -1;
// 			i++;
// 		}
// 		run_len *= 2;
// 	}
// }
// #include "push_swap.h"
// #include <stdio.h>
// int main()
// {
// 	t_stack *st_a = (t_stack *)malloc(sizeof(t_stack));
// 	t_stack *st_b = (t_stack *)malloc(sizeof(t_stack));
// 	// Initialize the stacks
// 	int stacka[50] = {11, 2, 3, 4, 99, 6, 7, 8, 9, -300, 12, 13, 14, 15, 16, 17, 18, 19, 60000, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 900, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53};
// 	st_a->st = stacka;
// 	st_a->h = 50;
// 	int stackb[50] = {0};
// 	st_b->st = stackb;
// 	st_b->h = 0;
// 	// Call distribute_runs
// 	int sorted = distribute_runs(st_a, st_b);
// 	sorted += 1;
// 	// while (st_a->st[0] > st_a->st[st_a->h - 1])
// 	// 	ra_wrapper(st_a->st, st_a->h);
// 	// // printf("runs: %d\n", count_runs(st_a->st, st_a->h));

// 	// Print the results
// 	// printf("Stack A: ");
// 	for (int i = 0; i < st_a->h; i++)
// 	{
// 		// printf("%d ", st_a->st[i]);
// 	}
// 	// printf("\n");
// 	// printf("Stack B: ");
// 	for (int i = 0; i < st_b->h; i++)
// 	{
// 		// printf("%d ", st_b->st[i]);
// 	}
// 	// printf("\n");
// 	// Free the stacks
// 	// free(st_a->st);
// 	// free(st_b->st);
// 	// free(st_a);
// 	// free(st_b);
// 	return 0;
// }
// cc distribute_runs.c ra.c pb.c rb.c ft_memmove.c
