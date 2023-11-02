/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:29:26 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 22:19:03 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*cptr;
	size_t	total;

	total = count * size;
	if ((count != 0 && total / count != size)
		|| (size != 0 && total / size != count))
		return (NULL);
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	cptr = (char *)ptr;
	while (total > 0)
	{
		*cptr = 0;
		cptr++;
		total--;
	}
	return (ptr);
}
