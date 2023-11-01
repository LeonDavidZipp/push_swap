/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:43:43 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 02:18:29 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


void	sa(int *stack_a, unsigned int height);
void	sb(int *stack_b, unsigned int height);
void	ss(int *stack_a, int *stack_b, int height_a, int height_b);

void	ra(int *stack_a, int height_a);
void	rb(int *stack_b, int height_b);
void	rr(int *stack_a, int *stack_b, int height_a, int height_b);

void	rra(int *stack_a, int height_a);
void	rrb(int *stack_b, int height_b);
void	rrr(int *stack_a, int *stack_b, int height_a, int height_b);

// helper functions
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strsepjoin(char const *s1, char const *s2, char const *sep);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

#endif