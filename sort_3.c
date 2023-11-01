/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:01:12 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 16:29:47 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack_a)
{
	if (stack_a->height <= 2)
		return (sort_2(stack_a));
	if (stack_a->stack[0] > stack_a->stack[1]
		&& stack_a->stack[2] > stack_a->stack[1]
		&& stack_a->stack[0] > stack_a->stack[2])
	{
		ra_wrapper(stack_a->stack, stack_a->height);
		return (stack_a);
	}
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
	if (stack_a->stack[1] > stack_a->stack[2])
		rra_wrapper(stack_a->stack, stack_a->height);
	if (stack_a->stack[0] > stack_a->stack[1])
		sa_wrapper(stack_a->stack, stack_a->height);
}
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
//     t_stack	*stack_a;
//     int i;
//     if (argc == 1)
//         return (0);
//     stack_a = make_stack_a(argc, argv);
//     sort_3(stack_a);//, stack_b);
//     // Print the sorted stack
//     for (i = 0; i < stack_a->height; i++)
//         printf("%d ", stack_a->stack[i]);
//     printf("\n");
//     free(stack_a->stack);
//     free(stack_a);
//     return (0);
// }
// cc sort_3.c sa.c make_stack_a.c make_stack_b.c ft_atoi.c ft_calloc.c
//  ft_isdigit.c ft_split.c ft_strcmp.c ft_strdup.c ft_strsepjoin.c
//  ft_strlen.c ft_substr.c sort_2.c rra.c ft_memmove.c ra.c
