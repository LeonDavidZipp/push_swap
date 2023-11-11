/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/11 17:07:02 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strsepjoin(char const *s1, char const *s2, char const *sep)
{
	char	*result;
	int		len1;
	int		len2;
	int		seplen;

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
	len1 = -1;
	while (s1[++len1])
		result[len1] = s1[len1];
	seplen = -1;
	while (sep[++seplen])
		result[len1 + seplen] = sep[seplen];
	len2 = -1;
	while (s2[++len2])
		result[len1 + seplen + len2] = s2[len2];
	return (result);
}
// #include <stdio.h>
// int main(void)
// {
// 	char const *s1 = "Hello";
// 	char const *s2 = "World";
// 	char const *sep = ", ";
// 	char *result = ft_strsepjoin(s1, s2, sep);
// 	if (result)
// 	{
// 		// printf("Result: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		// printf("Error: ft_strsepjoin returned NULL\n");
// 	}
// 	return 0;
// }
