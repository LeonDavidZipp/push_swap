/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:15:05 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 00:05:56 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Sorts stack_a using stack_b as a temporary stack.
/// @param stack_a 
/// @param stack_b 
/// @return 
void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int		unsorted;
	int		temp;

	if (stack_a->height <= 1)
		return ;
	if (stack_a->height <= 3)
	{
		sort_3_a(stack_a);
		return ;
	}
	while (stack_a->stack[0] > stack_a->stack[stack_a->height - 1])
		ra_wrapper(stack_a->stack, stack_a->height);
	unsorted = 1;
	while (unsorted)
	{
		temp = stack_a->stack[0];
		if (temp > stack_a->stack[1])
			sa_wrapper(stack_a->stack, stack_a->height);
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