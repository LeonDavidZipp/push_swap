/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 23:24:10 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strsepjoin(char const *s1, char const *s2, char const *sep)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	seplen;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	seplen = ft_strlen(sep);
	result = (char *)ft_calloc((len1 + seplen + len2 + 1), sizeof(char));
	if (!result)
		return (NULL);
	len1 = 0;
	while (s1[len1++])
		result[len1 - 1] = s1[len1 - 1];
	seplen = 0;
	while (sep[seplen++])
		result[len1 + seplen - 1] = sep[seplen - 1];
	len2 = 0;
	while (s2[len2++])
		result[len1 + seplen + len2 - 1] = s2[len2 - 1];
	return (result);
}
