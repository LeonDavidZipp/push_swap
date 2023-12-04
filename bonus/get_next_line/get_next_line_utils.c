/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:48:23 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/25 15:30:12 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	len1 = 0;
	while (s1 && s1[len1])
	{
		result[len1] = s1[len1];
		len1++;
	}
	len2 = 0;
	while (s2 && s2[len2])
	{
		result[len1 + len2] = s2[len2];
		len2++;
	}
	return (result);
}

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
	res = (char *)ft_calloc(j + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (start < s_len && s[start] && len > 0)
	{
		res[j++] = s[start++];
		len--;
	}
	return (res);
}
