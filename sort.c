/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:15:05 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 00:24:13 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
/// @return 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		temp;
	int		stack_flag;

	if (stack_a->height <= 1)
		return ;
	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
		ra_wrapper(stack_a->stack, stack_a->height);
	stack_flag = 1;
	while (1)
	{
		temp = stack_a->stack[0];
		while (temp > stack_a->stack[1])
		{
			if (stack_flag == 1)
			{
				ra_wrapper(stack_a->stack, stack_a->height);
				if (stack_a->height <= 3)
					sort_3_a(stack_a);
			}
			else if (stack_flag == -1)
			{
				pb_wrapper(stack_a, stack_b,
					&stack_a->height, &stack_b->height);
				rb_wrapper(stack_b->stack, stack_b->height);
				if (stack_b->height <= 3)
					sort_3_b(stack_b);
			}
			temp = stack_a->stack[0];
		}
		stack_flag *= -1;
		if (stack_b->height == 0)
			break;
	}
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