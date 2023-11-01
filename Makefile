# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:14:44 by lzipp             #+#    #+#              #
#    Updated: 2023/11/01 14:32:01 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wextra -Wall -Werror

SOURCES = bubblesort.c \
ft_calloc.c \
ft_memmove.c \
ft_strcmp.c \
ft_strlen.c \
ft_substr.c \
make_stack_b.c \
pb.c \
push_swap.h \
rb.c \
rra.c \
rrr.c \
sb.c \
ft_atoi.c \
ft_isdigit.c \
ft_split.c \
ft_strdup.c \
ft_strsepjoin.c \
make_stack_a.c \
pa.c \
push_swap.c \
ra.c \
rr.c \
rrb.c \
sa.c \
ss.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME)

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
