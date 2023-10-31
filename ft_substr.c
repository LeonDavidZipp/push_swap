/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:56 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/31 11:51:02 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	j = 0;
	s_len = ft_strlen(s);
	while (j + start < s_len && s[j + start] && j < len)
		j++;
	res = (char *)malloc((j + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (start < s_len && s[start] && len > 0)
	{
		res[j++] = s[start++];
		len--;
	}
	res[j] = '\0';
	return (res);
}
