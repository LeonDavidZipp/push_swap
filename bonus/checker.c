/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:51 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/18 12:41:18 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static void	free_stacks(t_stack *st_a, t_stack *st_b)
{
	free(st_a->st);
	free(st_a);
	free(st_b->st);
	free(st_b);
}

static void	print_result(t_stack *st_a, t_stack *st_b)
{
	if (is_sorted(st_a) && st_b->h == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	write(1, "Enter Instructions. Exit: d + Enter\n", 36);
	if (execute_commands(st_a, st_b) == 1)
	{
		write(2, "Error: Incorrect Instructions\n", 30);
		return (1);
	}
	print_result(st_a, st_b);
	free_stacks(st_a, st_b);
	return (0);
}
// Insert this snippet before return for leak testing:
// system("leaks checker");
// # ifndef OPEN_MAX
// #  define OPEN_MAX 10240
// # endif
