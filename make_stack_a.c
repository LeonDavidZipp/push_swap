/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/31 14:45:39 by lzipp            ###   ########.fr       */
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

int	*make_stack_a(int argc, char **argv)
{
	char	*num_string;
	char	**num_strings;
	int		*stack_a;
	int		height_a;

	num_string = join_input(argc, argv);
	if (!check_numeric(argc, argv) || !check_unique(argc, argv) || !num_string)
		return (NULL);
	num_strings = ft_split(num_string, ' ');
	free (num_string);
	if (!num_strings)
		return (NULL);
	height_a = 0;
	while (num_strings[height_a] != NULL)
		height_a++;
	stack_a = (int *)ft_calloc(height_a, sizeof(int));
	height_a = 0;
	while (num_strings[height_a++] != NULL)
		stack_a[height_a - 1] = ft_atoi(num_strings[height_a - 1]);
	return (stack_a);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	*stack_a;
	int height_a = argc - 1;

	if (argc == 1)
		return (0);
	stack_a = make_stack_a(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	for (int i = 0; i < height_a; i++)
	{
		printf("%d ", stack_a[i]);
	}
	printf("\n");
	return (0);
}
// cc make_stack_a.c ft_strdup.c ft_isdigit.c ft_strcmp.c ft_strsepjoin.c ft_calloc.c ft_strlen.c ft_atoi.c ft_split.c ft_substr.c