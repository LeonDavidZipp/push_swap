/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:34:45 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/31 10:07:27 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_input(int argc, char **argv)
{
	int		i;
	char	*num_string;
	char	*temp;
	char	*temp2;

	i = 1;
	num_string = NULL;
	while (i < argc)
	{
		temp = ft_strdup(argv[i]);
		if (num_string)
			temp2 = ft_strjoin(num_string, temp);
	}
}
