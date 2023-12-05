/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:09:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/05 15:04:19 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	rr(int *st_a, int *st_b, int h_a, int h_b)
{
	ra(st_a, h_a);
	rb(st_b, h_b);
}

void	rrr(int *st_a, int *st_b, int h_a, int h_b)
{
	rra(st_a, h_a);
	rrb(st_b, h_b);
}

void	ss(int *st_a, int *st_b, int h_a, int h_b)
{
	sa(st_a, h_a);
	sb(st_b, h_b);
}

static int	execute_command(char *str, t_stack *st_a, t_stack *st_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(st_a->st, st_a->h);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(st_b->st, st_b->h);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(st_a->st, st_b->st, st_a->h, st_b->h);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(st_a->st, st_b->st, &st_a->h, &st_b->h);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(st_a->st, st_b->st, &st_a->h, &st_b->h);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(st_a->st, st_a->h);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(st_b->st, st_b->h);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(st_a->st, st_b->st, st_a->h, st_b->h);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(st_a->st, st_a->h);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(st_b->st, st_b->h);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(st_a->st, st_b->st, st_a->h, st_b->h);
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
		free(command);
		command = get_next_line(0);
		if (execute_command(command, st_a, st_b) == 1)
		{
			free(command);
			return (1);
		}
	}
	free(command);
	return (0);
}
