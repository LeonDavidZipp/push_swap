/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:42:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/21 11:13:51 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	pa_ra_wrapper(int *st_a, int *st_b, int *h_a, int *h_b)
{
	pa_wrapper(st_a, st_b, h_a, h_b);
	ra_wrapper(st_a, *h_a);
}

// static void	rra_pa_ra_ra_wrapper(int *st_a, int *st_b, int *h_a, int *h_b)
// {
// 	rra_wrapper(st_a, *h_a);
// 	pa_ra_wrapper(st_a, st_b, h_a, h_b);
// 	ra_wrapper(st_a, *h_a);
// }

static void	sort_3(t_stack *st_a)
{
	if (st_a->h <= 2)
	{
		if (st_a->h <= 1)
			return ;
		if (st_a->st[0] > st_a->st[1])
			sa_wrapper(st_a->st, st_a->h);
		return ;
	}
	if (st_a->st[0] > st_a->st[1]
		&& st_a->st[2] > st_a->st[1]
		&& st_a->st[0] > st_a->st[2])
	{
		ra_wrapper(st_a->st, st_a->h);
		return ;
	}
	if (st_a->st[0] > st_a->st[1])
		sa_wrapper(st_a->st, st_a->h);
	if (st_a->st[1] > st_a->st[2])
		rra_wrapper(st_a->st, st_a->h);
	if (st_a->st[0] > st_a->st[1])
		sa_wrapper(st_a->st, st_a->h);
}

static void	sort_4(t_stack *st_a, t_stack *st_b)
{
	if (st_a->h <= 3)
	{
		sort_3(st_a);
		return ;
	}
	pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	sort_3(st_a);
	if (st_b->st[0] < st_a->st[0])
		pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	else if (st_b->st[0] > st_a->st[st_a->h - 1])
		pa_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	else if (st_b->st[0] > st_a->st[0] && st_b->st[0] < st_a->st[1])
	{
		ra_wrapper(st_a->st, st_a->h);
		pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		rra_wrapper(st_a->st, st_a->h);
	}
	else
	{
		rra_wrapper(st_a->st, st_a->h);
		pa_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
		ra_wrapper(st_a->st, st_a->h);
	}
}

/// @brief Sorts 5 or less elements
/// @param st_a stack a struct
/// @param st_b stack b struct
void	sort_5(t_stack *st_a, t_stack *st_b)
{
	if (st_a->h <= 4)
	{
		sort_4(st_a, st_b);
		return ;
	}
	pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	sort_3(st_a);
	st_a->runs = 1;
	if (st_b->st[0] > st_b->st[1])
		sb_wrapper(st_b->st, st_b->h);
	st_b->runs = 1;
	merge_to_a(st_a, st_b);
	st_b->runs = 0;
	// write(1, "------", 6);
	// sort_4(st_a, st_b);
	// write(1, "------", 6);
	// if (st_b->st[0] < st_a->st[0])
	// 	pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// else if (st_b->st[0] > st_a->st[st_a->h - 1])
	// 	pa_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// else if (st_b->st[0] > st_a->st[0] && st_b->st[0] < st_a->st[1])
	// {
	// 	ra_wrapper(st_a->st, st_a->h);
	// 	pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// 	rra_wrapper(st_a->st, st_a->h);
	// }
	// else if (st_b->st[0] > st_a->st[1] && st_b->st[0] < st_a->st[2])
	// {
	// 	rra_wrapper(st_a->st, st_a->h);
	// 	rra_pa_ra_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
	// 	ra_wrapper(st_a->st, st_a->h);
	// }
	// else
	// 	rra_pa_ra_ra_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
}

// void	sort_6(t_stack *st_a, t_stack *st_b)
// {
// 	if (st_a->h <= 4)
// 	{
// 		sort_4(st_a, st_b);
// 		return ;
// 	}
// 	if (st_a->h > 3)
// 		pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 	if (st_a->h > 3)
// 		pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 	if (st_a->h > 3)
// 		pb_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
// 	sort_3_a(st_a);
// 	st_a->runs = 1;
// 	sort_3_b(st_b);
// 	st_b->runs = 1;
// 	if (st_b->h > 0)
// 		merge_to_a(st_a, st_b);
// }

// int	main(void)
// {
// 	t_stack st_a, st_b;
//     st_a.stack = (int*)malloc(sizeof(int) * 6);
//     st_b.stack = (int*)malloc(sizeof(int) * 6);
//     st_a.height = 6;
//     st_b.height = 0;

//     // Fill st_a with some test data
//     st_a.stack[0] = 3;
//     st_a.stack[1] = 1;
//     st_a.stack[2] = 6;
//     st_a.stack[3] = 4;
//     st_a.stack[4] = 2;
//     st_a.stack[5] = 5;

//     // Call sort_6_a
//     sort_6_a(&st_a, &st_b);

//     // Check if the elements in st_a are sorted in ascending order
//     for (int i = 0; i < st_a.height; i++) {
//         printf("value: %d\n", st_a.stack[i]);
//     }

//     // Clean up
//     free(st_a.stack);
//     free(st_b.stack);
// }