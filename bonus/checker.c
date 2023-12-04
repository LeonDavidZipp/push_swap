/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:51 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 16:54:15 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (0);
	st_a = make_stack_a(argc, argv);
	if (!st_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	st_b = make_stack_b(st_a);
	if (!st_b)
		return (1);
	if (execute_commands() == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3)
	free(st_a->st);
	free(st_a);
	free(st_b->st);
	free(st_b);
	return (0);
}
