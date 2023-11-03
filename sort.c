/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/03 17:51:05 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack[0] > stack_b->stack[0])
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
	ra_wrapper(stack_a->stack, stack_a->height);
	while (stack_a->stack[stack_a->height - 1] < stack_a->stack[0])
	{
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
	while (stack_a->stack[stack_a->height - 1] < stack_b->stack[0])
	{
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
}

static void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->stack[0] > stack_a->stack[0])
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
	rb_wrapper(stack_b->stack, stack_b->height);
	while (stack_b->stack[stack_b->height - 1] < stack_b->stack[0])
	{
		if (stack_b->stack[0] > stack_a->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
	while (stack_b->stack[stack_b->height - 1] < stack_a->stack[0])
	{
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
}

/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_flag;

	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	if (stack_b->height <= 3)
	{
		sort_3_b(stack_b);
		return ;
	}
	if (distribute_runs(stack_a, stack_b) == 1)
		return ;
	stack_flag = 1;
	while (stack_b->height > 0)
	{
		if (stack_flag == 1)
			merge_to_a(stack_a, stack_b);
		else
			merge_to_b(stack_a, stack_b);
		stack_flag *= -1;
	}
}
#include "push_swap.h"
#include <stdio.h>
int main(void)
{
    t_stack stack_a;
    t_stack stack_b;
    // Initialize the heights of the stacks
    stack_b.height = 0;
    // Allocate memory for the stacks
	// int stacka[50] = {11, 2, 3, 4, 99, 6, 7, 8, 9, -300, 12, 13, 14, 15, 16, 17, 18, 19, 60000, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 900, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52, 53};
    int stacka[6] = {4, 67, 3, 87, 100, 10000};
	stack_a.stack = stacka;
    // stack_a.height = 50;
	stack_a.height = 6;
    int stackb[50] = {0};
    stack_b.stack = stackb;
    stack_b.height = 0;
    // Fill stack_a with some unsorted numbers
    // stack_a.stack[0] = 5;
    // stack_a.stack[1] = 6;
    // stack_a.stack[2] = 4;
    // stack_a.stack[3] = 2;
    // stack_a.stack[4] = 1;
	// stack_a.stack[5] = 1000;
    // Sort stack_a using stack_b as a temporary stack
    sort(&stack_a, &stack_b);
    // Print the sorted numbers
    for (int i = 0; i < stack_a.height; i++)
    {
        printf("%d ", stack_a.stack[i]);
    }
    printf("\n");
    return 0;
}
// cc sort.c pb.c rb.c ft_memmove.c sort_3.c sort_2.c distribute_runs.c ra.c rra.c rrb.c sa.c sb.c pa.c
