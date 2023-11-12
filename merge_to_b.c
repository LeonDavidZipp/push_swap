/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/12 11:23:26 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	merge_helper(int *st_a, int *st_b,
	int *h_a, int *h_b)
{
	rb_wrapper(st_b, *h_b);
	pb_wrapper(st_a, st_b, h_a, h_b);
}

/// @brief Merges the etopmost run of stack a to stack b
/// @param st_a stack a struct
/// @param st_b stack b struct
void	merge_to_b(t_stack *st_a, t_stack *st_b)
{
	int		temp_a;
	int		temp_b;

	temp_b = st_b->st[0];
	temp_a = st_a->st[0];
	while (st_a->h >= 1 && temp_a <= st_a->st[0])
	{
		temp_a = st_a->st[0];
		if (st_b->st[0] > st_a->st[0])
			pb_wrapper(st_a->st, st_b->st,
				&(st_a->h), &(st_b->h));
		else if (st_b->st[0] > st_b->st[1]
			&& st_b->st[0] < st_a->st[0])
			merge_helper(st_a->st, st_b->st,
				&(st_a->h), &(st_b->h));
		rb_wrapper(st_b->st, st_b->h);
		temp_b = st_a->st[0];
	}
	// while (st_b->runs > 1 && (temp_b <= st_b->st[0]
	while ((temp_b <= st_b->st[0]
			|| st_b->st[0] > st_b->st[1]))
	{
		temp_b = st_b->st[0];
		rb_wrapper(st_b->st, st_b->h);
	}
}

// for merging

// int main(int argc, char **argv)
// {
// 	t_stack	*st_a = make_stack_a(argc, argv);
// 	t_stack	*st_b = make_stack_b(st_a);

// 	distribute_runs(st_a, st_b);
// 	// printf("stack a before merge:	");
// 	for (int i = 0; i < st_a->h; i++) {
// 	// printf("%d, ", st_a->st[i]);
// 		}
// 		// printf("\n");
// 		// // printf("hi");
// 	// printf("stack b:	");
// 		for (int i = 0; i < st_b->h; i++) {
// 	// printf("%d, ", st_b->st[i]);
// 		}
// 		// // printf("hi");
// 	// printf("\n");
// 	// printf("merging stack a to stack b\n");
// 	merge_to_b(st_a, st_b);
// 	// Print the values in stack A after the merge
// 	// printf("stack a:	");
// 	for (int i = 0; i < st_a->h; i++) {
// 	// printf("%d, ", st_a->st[i]);
// 		}
// 		// printf("\n");
// 		// // printf("hi");
// 	// printf("stack b:	");
// 		for (int i = 0; i < st_b->h; i++) {
// 	// printf("%d, ", st_b->st[i]);
// 		}
// 		// // printf("hi");
// 	// printf("\n");
// 	return 0;
// }
