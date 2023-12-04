/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:19:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 17:09:38 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stack *st_a, t_stack *st_b)
{
	free(st_a->st);
	free(st_a);
	free(st_b->st);
	free(st_b);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (1);
	st_a = make_stack_a(argc, argv);
	if (!st_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	st_b = make_stack_b(st_a);
	if (!st_b)
		return (1);
	k_sort(st_a, st_b);
	free_stacks(st_a, st_b);
	return (0);
}
