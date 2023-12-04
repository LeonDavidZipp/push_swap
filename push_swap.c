/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:19:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:38:11 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (0);
	st_a = make_stack_a(argc, argv);
	if (!st_a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	st_b = make_stack_b(st_a);
	if (!st_b)
		return (0);
	k_sort(st_a, st_b);
	free(st_a->st);
	free(st_a);
	free(st_b->st);
	free(st_b);
	return (0);
}
