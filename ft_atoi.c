/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:29:13 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/13 13:17:14 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((result * sign));
}
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	printf("ft_atoi: expected output: 0 | %d\n", ft_atoi(NULL));
//     printf("atoi: expected output: 0 | %d\n", atoi("a\n123"));
//     printf("ft_atoi: expected output: -123 | %d\n", ft_atoi("     -123"));
//     printf("atoi: expected output: -123 | %d\n", atoi("     -123"));
//     printf("ft_atoi: expected output: 0 | %d\n", ft_atoi("0"));
//     printf("atoi: expected output: 0 | %d\n", atoi("0"));
//     printf("ft_atoi: expected output: 123 | %d\n", ft_atoi("  123"));
//     printf("atoi: expected output: 123 | %d\n", atoi("  123"));
//     printf("ft_atoi: expected output: 123 | %d\n", ft_atoi("123 456"));
//     printf("atoi: expected output: 123 | %d\n", atoi("123 456"));
//     printf("ft_atoi: expected output: 123 | %d\n", ft_atoi("  +123"));
//     printf("atoi: expected output: 123 | %d\n", atoi("  +123"));
//     printf("ft_atoi: expected output: -123 | %d\n", ft_atoi("  -123"));
//     printf("atoi: expected output: -123 | %d\n", atoi("  -123"));
//     printf("ft_atoi: expected output: 123 | %d\n", ft_atoi("123abc"));
//     printf("atoi: expected output: 123 | %d\n", atoi("123abc"));
// 	printf("atoi: expected output: 123 | %d\n", atoi("123abc"));
// 	return (0);
// }
