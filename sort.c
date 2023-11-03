/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/03 09:57:04 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack[0] > stack_b->stack[0])
	{
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
	else if (stack_a->stack[0] < stack_b->stack[0])
		ra_wrapper(stack_a->stack, stack_a->height);
	while (stack_a->stack[stack_a->height - 1] <= stack_a->stack[0])
	{
		if (stack_a->stack[0] > stack_b->stack[0])
			pa_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
	while (stack_a->stack[stack_a->height - 1] <= stack_b->stack[0])
	{
		pa_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		ra_wrapper(stack_a->stack, stack_a->height);
	}
}

static void	merge_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->stack[0] > stack_a->stack[0])
	{
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
	else if (stack_b->stack[0] < stack_a->stack[0])
		rb_wrapper(stack_b->stack, stack_b->height);
	while (stack_b->stack[stack_b->height - 1] <= stack_b->stack[0])
	{
		if (stack_b->stack[0] > stack_a->stack[0])
			pb_wrapper(stack_a->stack, stack_b->stack,
				&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
	while (stack_b->stack[stack_b->height - 1] <= stack_a->stack[0])
	{
		pb_wrapper(stack_a->stack, stack_b->stack,
			&(stack_a->height), &(stack_b->height));
		rb_wrapper(stack_b->stack, stack_b->height);
	}
}

#include<stdio.h>
/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		runs;
	int		stack_flag;

	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	if (distribute_runs(stack_a, stack_b) == 1)
		return ;
	stack_flag = 1;
	while (stack_b->height > 0)
	{
		merge_to_a(stack_a, stack_b);
		merge_to_b(stack_a, stack_b);
		printf("stack A: ");
		for (int i = 0; i < stack_a->height; i++)
			printf("%d ", stack_a->stack[i]);
		printf("\n");
		printf("stack B: ");
		for (int i = 0; i < stack_b->height; i++)
			printf("%d ", stack_b->stack[i]);
		printf("\n");
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
    stack_a.height = 5;
    stack_b.height = 0;

    // Allocate memory for the stacks
    stack_a.stack = malloc(stack_a.height * sizeof(int));
    stack_b.stack = malloc(stack_a.height * sizeof(int));

    // Fill stack_a with some unsorted numbers
    stack_a.stack[0] = 3;
    stack_a.stack[1] = 1;
    stack_a.stack[2] = 4;
    stack_a.stack[3] = 2;
    stack_a.stack[4] = 5;

    // Sort stack_a using stack_b as a temporary stack
    sort(&stack_a, &stack_b);

    // Print the sorted numbers
    for (int i = 0; i < stack_a.height; i++)
    {
        printf("%d ", stack_a.stack[i]);
    }
    printf("\n");

    // Free the memory allocated for the stacks
    free(stack_a.stack);
    free(stack_b.stack);

    return 0;
}
// cc sort.c pb.c rb.c ft_memmove.c sort_3.c sort_2.c distribute_runs.c ra.c rra.c rrb.c sa.c sb.c pa.c