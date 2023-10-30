/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:19:48 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/30 10:28:10 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	// prevent wrong input
	if (argc <= 1) // missing: letters, duplicates, other symbols
		return (0);
	populate_stack_a(argv); // write input to stack_a
	
	return (0);
}
