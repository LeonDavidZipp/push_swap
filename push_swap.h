/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:43:43 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/31 10:45:41 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

void	sa(int *stack_a, unsigned int height);
void	sb(int *stack_b, unsigned int height);
void	ss(int *stack_a, int *stack_b, int height_a, int height_b);

void	ra(int *stack_a, int height_a);
void	rb(int *stack_b, int height_b);
void	rr(int *stack_a, int *stack_b, int height_a, int height_b);

void	rra(int *stack_a, int height_a);
void	rrb(int *stack_b, int height_b);
void	rrr(int *stack_a, int *stack_b, int height_a, int height_b);

void	*ft_memmove(void *dst, const void *src, size_t len);

#endif