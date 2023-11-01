/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 11:35:21 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_unique(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && !ft_strcmp(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	*join_input(int argc, char **argv)
{
	int		i;
	char	*num_string;
	char	*temp;

	i = 1;
	num_string = NULL;
	while (i < argc)
	{
		temp = ft_strsepjoin(num_string, argv[i++], " ");
		free (num_string);
		if (!temp)
			return (NULL);
		num_string = ft_strdup(temp);
		free (temp);
	}
	return (num_string);
}

static t_stack	*build_stack(char **num_strings)
{
	t_stack	*stack_a;
	int		*stack;
	int		height_a;
	long	num;

	height_a = 0;
	while (num_strings[height_a] != NULL)
		height_a++;
	stack = (int *)ft_calloc(height_a, sizeof(int));
	if (!stack)
		return (NULL);
	height_a = -1;
	while (num_strings[++height_a] != NULL)
	{
		num = ft_atoi(num_strings[height_a]);
		if (num > INT_MAX || num < INT_MIN)
			return (NULL);
		stack[height_a] = (int)num;
	}
	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->stack = stack;
	stack_a->height = height_a;
	return (stack_a);
}

t_stack	*make_stack_a(int argc, char **argv)
{
	char	*num_string;
	char	**num_strings;

	num_string = join_input(argc, argv);
	if (!check_numeric(argc, argv) || !check_unique(argc, argv) || !num_string)
		return (NULL);
	num_strings = ft_split(num_string, ' ');
	free (num_string);
	if (!num_strings)
		return (NULL);
	return (build_stack(num_strings));
}
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	int		height_a;
// 	int		*stack;

// 	if (argc == 1)
// 		return (0);
// 	stack_a = make_stack_a(argc, argv);
// 	if (!stack_a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	height_a = stack_a->height;
// 	stack = stack_a->stack;
// 	for (int i = 0; i < height_a; i++)
// 	{
// 		printf("|%d|\n", stack[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
// cc make_stack_a.c ft_strdup.c ft_isdigit.c ft_strcmp.c ft_strsepjoin.c
// ft_calloc.c ft_strlen.c ft_atoi.c ft_split.c ft_substr.c
