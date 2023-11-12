/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:37:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/12 11:23:26 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// static void	merge_helper(int *st_a, int *st_b, int *h_a, int *h_b)
// {
// 	ra_wrapper(st_a, *h_a);
// 	pa_wrapper(st_a, st_b, h_a, h_b);
// }

/// @brief Merges the topmost run of stack b to stack a
/// @param st_a stack a struct
/// @param st_b stack b struct
// void	merge_to_a(t_stack *st_a, t_stack *st_b)
// {
// 	int		temp_a;
// 	int		temp_b;

// 	temp_b = st_b->st[0];
// 	temp_a = st_a->st[0];
// 	while (st_b->h >= 1 && temp_b <= st_b->st[0])
// 	{
// 		temp_b = st_b->st[0];
// 		if (st_a->st[0] > st_b->st[0])
// 			pa_wrapper(st_a->st, st_b->st,
// 				&(st_a->h), &(st_b->h));
// 		if (st_a->st[0] > st_a->st[1] && st_a->st[0] < st_b->st[0])
// 			merge_helper(st_a->st, st_b->st,
// 				&(st_a->h), &(st_b->h));
// 		ra_wrapper(st_a->st, st_a->h);
// 		temp_a = st_a->st[0];
// 	}
// 	while (st_a->runs > 1 && (temp_a <= st_a->st[0]
// 	// while ((temp_a <= st_a->st[0]
// 			|| st_a->st[0] > st_a->st[1]))
// 	{
// 		temp_a = st_a->st[0];
// 		ra_wrapper(st_a->st, st_a->h);
// 	}
// }

// if top of B < top of A:
//     pa
// ra
// while bottom of A <= top of A:
//     if top of B < top of A:
//         pa
//     ra
// while bottom of B <= top of A:
//     pa
//     ra

void	merge_to_a(t_stack *st_a, t_stack *st_b)
{
	if (st_b->st[0] < st_a->st[0])
		pa_wrapper(st_a->st, st_b->st,
			&(st_a->h), &(st_b->h));
	ra_wrapper(st_a->st, st_a->h);
	while (st_a->h > 0 && st_a->st[st_a->h -1] <= st_a->st[0])
	{
		// printf("\n1st while-----------\n");
		if (st_b->st[0] < st_a->st[0])
			pa_wrapper(st_a->st, st_b->st,
				&(st_a->h), &(st_b->h));
		ra_wrapper(st_a->st, st_a->h);
	}
	while (st_b->h > 0 && st_b->st[st_b->h - 1] <= st_a->st[0])
	{
		// printf("\n2nd while-----------\n");
		pa_wrapper(st_a->st, st_b->st,
			&(st_a->h), &(st_b->h));
		ra_wrapper(st_a->st, st_a->h);
	}
	while (st_b->h > 0 && st_b->st[0] > st_a->st[0])
	{
		// printf("\n3rd while-----------\n");
		pa_wrapper(st_a->st, st_b->st,
			&(st_a->h), &(st_b->h));
		ra_wrapper(st_a->st, st_a->h);
	}
}
// #include <stdio.h>
// int main() {
//     t_stack *st_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
//     t_stack *st_b = (t_stack *)ft_calloc(1, sizeof(t_stack));

//     // Initialize the heights of the stacks
//     st_a->h = 3;
//     st_b->h = 2;

//     // Initialize the stacks with some values
//     int st_a_values[12] = {2, 4, 5, 0, 0, 0, 0,0 ,0 ,0 ,0 ,0};
//     // int st_b_values[] = {-3, 111, 308, 700, 6};
//     int st_b_values[12] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     st_a->st = st_a_values;
//     st_b->st = st_b_values;

//     // Call the merge_to_a function
//     merge_to_a(st_a, st_b);

//     // Print the values in stack A after the merge
//     for (int i = 0; i < st_a->h; i++) {
//         // printf("%d, ", st_a->st[i]);
//     }
// 	// // printf("hi");
//     // printf("\n");
// 	for (int i = 0; i < st_b->h; i++) {
//         // printf("%d, ", st_b->st[i]);
//     }
// 	// // printf("hi");
//     // printf("\n");
//     return (0);
// }
