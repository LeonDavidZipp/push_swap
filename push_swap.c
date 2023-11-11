/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:19:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 14:18:32 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (0);
	st_a = make_st_a(argc, argv);
	if (!st_a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	st_b = make_st_b(st_a);
	if (!st_b)
		return (0);
	sort(st_a, st_b);
	printf("stack a and height: %d \n", st_a->height);
	for (int i = 0; i < st_a->height; i++)
	{
		printf("%d ", st_a->stack[i]);
	}
	printf("\n");
	printf("stack b: ");
	for (int i = 0; i < st_b->height; i++)
	{
		printf("%d ", st_b->stack[i]);
	}
	printf("\n");
	return (0);
}
