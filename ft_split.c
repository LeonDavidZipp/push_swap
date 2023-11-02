/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:32:23 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/02 22:19:11 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_split_str(const char *s, char c, int *i)
{
	size_t	len;

	len = *i;
	while (s[*i] != c && s[*i])
		(*i)++;
	(*i)--;
	return (ft_substr(s, len, *i - len + 1));
}

static void	*ft_free_mem(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
		free(result[i++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	words = ft_count_words(s, c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	result[words] = NULL;
	while (s[++i] && j < words)
	{
		if (s[i] != c)
		{
			result[j++] = ft_split_str(s, c, &i);
			if (!result[j - 1])
				return (ft_free_mem(result));
		}
	}
	return (result);
}
// #include <stdio.h>
// int main() {
//     const char *input = "This is a test string";
//     char **result = ft_split(input, ' ');
// 	system("leaks a.out");

//     if (!result) {
//         printf("Memory allocation error in ft_split\n");
//         return 1;
//     }

//     // Print the split strings
//     for (int i = 0; result[i] != NULL; i++) {
//         printf("Token %d: %s\n", i, result[i]);
//     }

//     // Free the memory allocated by ft_split
//     for (int i = 0; result[i] != NULL; i++) {
//         free(result[i]);
//     }
//     free(result);
//     return 0;
// }
