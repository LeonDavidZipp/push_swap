/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:15:05 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 10:50:59 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Counts the number of runs in stack_a.
/// A run is a sequence of numbers that are in ascending order.
/// @param stack_a 
/// @return 
static int	count_runs(t_stack *stack_a)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < stack_a->height - 1)
	{
		if (stack_a->stack[i] > stack_a->stack[i + 1])
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
	int		stack_flag;

	temp = stack_a->stack[0];
	while (temp < stack_a->stack[1])
	{
		if (stack_flag == 1)
			ra_wrapper(stack_a->stack, stack_a->height);
		else if (stack_flag == -1)
		{
			pb_wrapper(stack_a, stack_b,
				&stack_a->height, &stack_b->height);
			rb_wrapper(stack_b->stack, stack_b->height);
		}
		temp = stack_a->stack[0];
	}
}

/// @brief Distributes the runs evenly between stack_a and stack_b.
/// @param stack_a 
/// @param stack_b 
static void	distribute_runs(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_flag;
	int		runs_a;
	int		runs_b;

	while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
		ra_wrapper(stack_a->stack, stack_a->height);
	stack_flag = 1;
	runs_a = count_runs(stack_a);
	runs_b = 0;
	while (runs_a != runs_b && runs_a != runs_b + 1 && runs_a != runs_b - 1)
	{
		move_run(stack_a, stack_b, stack_flag);
		runs_a--;
		runs_b++;
		stack_flag *= -1;
	}
}

/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		runs;

	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	distribute_runs(stack_a, stack_b);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    int i;

    if (argc == 1)
        return (0);
    stack_a = make_stack_a(argc, argv);
    stack_b = make_stack_b(*stack_a);
    bubblesort(stack_a);//, stack_b);

    // Print the sorted stack
    for (i = 0; i < stack_a->height; i++)
    {
        printf("%d ", stack_a->stack[i]);
    }
    printf("\n");

    free(stack_a->stack);
    free(stack_b->stack);
    free(stack_a);
    free(stack_b);
    return (0);
}
// cc bubblesort.c sa.c make_stack_a.c make_stack_b.c ft_atoi.c ft_calloc.c ft_isdigit.c ft_split.c ft_strcmp.c ft_strdup.c ft_strsepjoin.c ft_strlen.c ft_substr.c 