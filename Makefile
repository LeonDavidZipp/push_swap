# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:14:44 by lzipp             #+#    #+#              #
#    Updated: 2023/11/12 16:32:57 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wextra -Wall -Werror

SOURCES = distribute_runs.c \
ft_atoi.c \
ft_calloc.c \
ft_isdigit.c \
ft_memmove.c \
ft_split.c \
ft_strcmp.c \
ft_strdup.c \
ft_strlen.c \
ft_strsepjoin.c \
ft_substr.c \
make_stack_a.c \
make_stack_b.c \
merge_to_a.c \
merge_to_b.c \
pa.c \
pb.c \
push_swap.c \
ra.c \
rb.c \
rr.c \
rra.c \
rrb.c \
rrr.c \
sa.c \
sb.c \
sort_5.c \
sort.c \
ss.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

cm: all clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re cm
