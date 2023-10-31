/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/31 10:59:55 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// int		i;

	num_string = join_input(argc, argv);
	if (!num_string)
		return (NULL);
	num_strings = ft_split(num_string, " ");
	free (num_string);
	if (!num_strings)
		return (NULL);
	height_a = 0;
	while (num_strings[height_a] != NULL)
		height_a++;
	stack_a = (int *)ft_calloc(height_a, sizeof(int));
	height_a = 0;
	while (num_strings[height_a] != NULL)
	{
		stack_a[height_a] = ft_atoi()
	}
}
