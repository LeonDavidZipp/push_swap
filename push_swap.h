/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:43:43 by lzipp             #+#    #+#             */
/*   Updated: 2023/12/02 17:49:53 by lzipp            ###   ########.fr       */
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
int		count_rotate(t_stack *st, int min_el);
int		count_reverse_rotate(t_stack *st, int min_el);

// stack creation
t_stack	*make_stack_a(int argc, char **argv);
t_stack	*make_stack_b(t_stack *st_a);

// run functions
int		distribute_runs(t_stack *st_a, t_stack *st_b);

// merge functions
void	merge_to_a(t_stack *st_a, t_stack *st_b);
void	merge_to_b(t_stack *st_a, t_stack *st_b);

// sorting functions
void	sort_7(t_stack *st_a, t_stack *st_b);
void	sort(t_stack *st_a, t_stack *st_b);

// stack manipulation functions
void	pa(int *st_a, int *st_b, int *h_a, int *h_b);
void	pa_wrapper(int *st_a, int *st_b, int *h_a, int *h_b);
void	pb(int *st_a, int *st_b, int *h_a, int *h_b);
void	pb_wrapper(int *st_a, int *st_b, int *h_a, int *h_b);

void	sa(int *st_a, int h_a);
void	sa_wrapper(int *st_a, int h_a);
void	sb(int *st_b, int height);
void	sb_wrapper(int *st_b, int h_b);
void	ss(int *st_a, int *st_b, int h_a, int h_b);
void	ss_wrapper(int *st_a, int *st_b, int h_a, int h_b);

void	ra(int *st_a, int h_a);
void	ra_wrapper(int *st_a, int h_a);
void	rb(int *st_b, int h_b);
void	rb_wrapper(int *st_b, int h_b);
void	rr(int *st_a, int *st_b, int h_a, int h_b);
void	rr_wrapper(int *st_a, int *st_b, int h_a, int h_b);

void	rra(int *st_a, int h_a);
void	rra_wrapper(int *st_a, int h_a);
void	rrb(int *st_b, int h_b);
void	rrb_wrapper(int *st_b, int h_b);
void	rrr(int *st_a, int *st_b, int h_a, int h_b);
void	rrr_wrapper(int *st_a, int *st_b, int h_a, int h_b);

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