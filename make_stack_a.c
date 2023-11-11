/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_st_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/05 18:55:09 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_numeric(int argc, char **argv)
{
	int		i;
	int		j;
	int		sign_flag;

	i = 1;
	sign_flag = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
			else if ((argv[i][j] == '-' || argv[i][j] == '+') && sign_flag == 0)
				sign_flag = 1;
			else if (ft_isdigit(argv[i][j]))
				sign_flag = 0;
			else if (!ft_isdigit(argv[i][j]) && sign_flag == 1)
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

static t_stack	*build_stack(char **num_strings, int h_a)
{
	t_stack	*st_a;
	int		*stack;
	long	num;

	stack = (int *)ft_calloc(h_a, sizeof(int));
	if (!stack)
		return (NULL);
	h_a = -1;
	while (num_strings[++h_a] != NULL)
	{
		num = ft_atoi(num_strings[h_a]);
		if (num > INT_MAX || num < INT_MIN)
			return (NULL);
		stack[h_a] = (int)num;
	}
	st_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!st_a)
		return (NULL);
	st_a->stack = stack;
	st_a->height = h_a;
	st_a->runs = 0;
	return (st_a);
}

/// @brief Generates stack a from the terminal input
/// @param argc 
/// @param argv 
/// @return stack a
t_stack	*make_stack_a(int argc, char **argv)
{
	char	*num_string;
	char	**num_strings;
	int		h_a;

	num_string = join_input(argc, argv);
	if (!check_numeric(argc, argv) || !check_unique(argc, argv) || !num_string)
		return (NULL);
	num_strings = ft_split(num_string, ' ');
	free (num_string);
	if (!num_strings)
		return (NULL);
	h_a = 0;
	while (num_strings[h_a] != NULL)
		h_a++;
	return (build_stack(num_strings, h_a));
}
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	t_stack	*st_a;
// 	int		h_a;
// 	int		*stack;

// 	if (argc == 1)
// 		return (0);
// 	st_a = make_st_a(argc, argv);
// 	if (!st_a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	h_a = st_a->height;
// 	stack = st_a->stack;
// 	for (int i = 0; i < h_a; i++)
// 	{
// 		printf("|%d|\n", stack[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
// cc make_st_a.c ft_strdup.c ft_isdigit.c ft_strcmp.c ft_strsepjoin.c
// ft_calloc.c ft_strlen.c ft_atoi.c ft_split.c ft_substr.c
