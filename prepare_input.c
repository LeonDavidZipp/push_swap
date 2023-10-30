/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 23:40:13 by lzipp            ###   ########.fr       */
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

int	*prepare_stack_a(int argc, char **argv)
{
	char	*num_string;
	char	**num_strings;
	int		height_a;

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
}
