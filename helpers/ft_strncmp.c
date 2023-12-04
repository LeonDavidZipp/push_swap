/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:33:17 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 18:05:03 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || n == 0)
		return (0);
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char str1[] = "2222";
// 	char str2[] = "22266";
// 	char str3[] = "Hello World";
// 	printf("ft_str: %i\n", ft_strncmp(str1, str2, 10));
// 	printf("ft_str: %i\n", strncmp(str1, str2, 6));
// 	printf("str: %i\n", ft_strncmp(&str1[0], &str3[0], 7));
// 	printf("str: %i\n", strncmp(&str1[0], &str3[0], 7));
// 	return (0);
// }
