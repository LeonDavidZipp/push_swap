/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:43:43 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/04 14:49:31 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// stack struct
typedef struct s_stack {
	int	*st;
	int	h;
	int	runs;
}	t_stack;

// helper functions
int		is_sorted(t_stack *st);
int		get_index(int *tab, int nb);
int		smallest_element(t_stack *st);
int		count_rotate(t_stack *st, int el);
int		count_reverse_rotate(t_stack *st, int el);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strsepjoin(char const *s1, char const *s2, char const *sep);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_sqrt(int nb);

// stack creation
t_stack	*make_stack_a(int argc, char **argv);
t_stack	*make_stack_b(t_stack *st_a);

// sorting functions
void	sort_3(t_stack *st_a);
void	sort_7(t_stack *st_a, t_stack *st_b);
void	k_sort(t_stack *st_a, t_stack *st_b);

// stack manipulation functions
void	pa(int *st_a, int *st_b, int *h_a, int *h_b);
void	pa_wrapper(int *st_a, int *st_b, int *h_a, int *h_b);
void	pb(int *st_a, int *st_b, int *h_a, int *h_b);
void	pb_wrapper(int *st_a, int *st_b, int *h_a, int *h_b);

void	sa(int *st_a, int h_a);
void	sa_wrapper(int *st_a, int h_a);
void	sb(int *st_b, int height);
void	sb_wrapper(int *st_b, int h_b);

void	ra(int *st_a, int h_a);
void	ra_wrapper(int *st_a, int h_a);
void	rb(int *st_b, int h_b);
void	rb_wrapper(int *st_b, int h_b);

void	rra(int *st_a, int h_a);
void	rra_wrapper(int *st_a, int h_a);
void	rrb(int *st_b, int h_b);
void	rrb_wrapper(int *st_b, int h_b);

#endif
