/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:09:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 16:52:07 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr_wrapper(int *st_a, int *st_b, int height_a, int height_b)
{
	ra(st_a, height_a);
	rb(st_b, height_b);
	write(1, "rr\n", 3);
}

void	rrr_wrapper(int *st_a, int *st_b, int height_a, int height_b)
{
	rra(st_a, height_a);
	rrb(st_b, height_b);
	write(1, "rrr\n", 4);
}

void	ss_wrapper(int *st_a, int *st_b, int height_a, int height_b)
{
	sa(st_a, height_a);
	sb(st_b, height_b);
	write(1, "ss\n", 3);
}

static int	execute_command(char *str, t_stack *st_a, t_stack *st_b)
{
	if (ft_strncmp(str, "sa\n", 4) == 0)
		sa_wrapper(st_a->st, st_b->st);
	else if (ft_strncmp(str, "sb\n", 4) == 0)
		sb_wrapper(st_a->st, st_b->st);
	else if (ft_strncmp(str, "ss\n", 4) == 0)
		ss_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
	else if (ft_strncmp(str, "pa\n", 4) == 0)
		pa_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
	else if (ft_strncmp(str, "pb\n", 4) == 0)
		pb_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
	else if (ft_strncmp(str, "ra\n", 4) == 0)
		ra_wrapper(st_a->st, st_b->st);
	else if (ft_strncmp(str, "rb\n", 4) == 0)
		rb_wrapper(st_a->st, st_b->st);
	else if (ft_strncmp(str, "rr\n", 4) == 0)
		rr_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
	else if (ft_strncmp(str, "rra\n", 5) == 0)
		rra_wrapper(st_a->st, st_b->st);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		rrb_wrapper(st_a->st, st_b->st);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
		rrr_wrapper(st_a->st, st_b->st, st_a->h, st_b->h);
	else
		return (1);
	return (0);
}

int	execute_commands(t_stack *st_a, t_stack *st_b)
{
	char	*command;

	command = ft_calloc(3, sizeof(char));
	while (command)
	{
		command = get_next_line(0);
		if (ft_strncmp(command, "d\n", 5) == 0)
			break ;
		if (execute_command(command, st_a, st_b) == 1)
			return (1);
	}
	free(command);
	return (0);
}
