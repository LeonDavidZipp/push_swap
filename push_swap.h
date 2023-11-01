/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:43:43 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/01 12:56:27 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// stack struct
typedef struct s_stack {
	int	*stack;
	int	height;
}	t_stack;

// stack creation
t_stack	*make_stack_a(int argc, char **argv);
t_stack	*make_stack_b(t_stack stack_a);

// stack manipulation functions
void	pa(int *stack_a, int *stack_b, int *height_a, int *height_b);
void	pa_wrapper(int *stack_a, int *stack_b, int *height_a, int *height_b);
void	pb(int *stack_a, int *stack_b, int *height_a, int *height_b);
void	pb_wrapper(int *stack_a, int *stack_b, int *height_a, int *height_b);

void	sa(int *stack_a, int height_a);
void	sa_wrapper(int *stack_a, int height_a);
void	sb(int *stack_b, int height);
void	sb_wrapper(int *stack_b, int height_b);
void	ss(int *stack_a, int *stack_b, int height_a, int height_b);
void	ss_wrapper(int *stack_a, int *stack_b, int height_a, int height_b);

void	ra(int *stack_a, int height_a);
void	ra_wrapper(int *stack_a, int height_a);
void	rb(int *stack_b, int height_b);
void	rb_wrapper(int *stack_b, int height_b);
void	rr(int *stack_a, int *stack_b, int height_a, int height_b);
void	rr_wrapper(int *stack_a, int *stack_b, int height_a, int height_b);

void	rra(int *stack_a, int height_a);
void	rra_wrapper(int *stack_a, int height_a);
void	rrb(int *stack_b, int height_b);
void	rrb_wrapper(int *stack_b, int height_b);
void	rrr(int stack_a, int stack_b, int height_a, int height_b);
void	rrr_wrapper(int *stack_a, int *stack_b, int height_a, int height_b);

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