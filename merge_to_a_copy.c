/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:37:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/22 13:52:23 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	merge_to_a(t_stack *st_a, t_stack *st_b)
{
	int		run_len;
	int		i;
	int		temp;

	run_len = 1;
	while(run_len < st_a->h - 1 && st_a->st[run_len] < st_a->st[run_len + 1])
		run_len++;
	temp = st_b->st[0];
	i = 0;
	while (st_b->h > 0 && st_b->st[0] <= temp)
	{
		if (st_b->st[0] < st_a->st[0])
		{
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
			ra_wrapper(st_a->st, &st_a->h);
		}
		else if (i == run_len && st_b->st[0] > st_a->st[0])
		{
			pa_wrapper(st_a->st, st_b->st, &st_a->h, &st_b->h);
			ra_wrapper(st_a->st, &st_a->h);
		}
		else
		{
			ra_wrapper(st_a->st, &st_a->h);
			i++;
		}
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
