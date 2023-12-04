# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:14:44 by lzipp             #+#    #+#              #
#    Updated: 2023/12/04 14:50:45 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wextra -Wall -Werror

HELPERDIR = ./helpers
STACKOPSDIR = ./stack_ops
SORTDIR = ./sort

SOURCES = \
$(HELPERDIR)/ft_atol.c \
$(HELPERDIR)/ft_calloc.c \
$(HELPERDIR)/ft_isdigit.c \
$(HELPERDIR)/ft_memmove.c \
$(HELPERDIR)/ft_split.c \
$(HELPERDIR)/ft_strcmp.c \
$(HELPERDIR)/ft_strdup.c \
$(HELPERDIR)/ft_strlen.c \
$(HELPERDIR)/ft_strsepjoin.c \
$(HELPERDIR)/ft_substr.c \
$(HELPERDIR)/ft_sqrt.c \
$(STACKOPSDIR)/make_stack_a.c \
$(STACKOPSDIR)/make_stack_b.c \
$(STACKOPSDIR)/pa.c \
$(STACKOPSDIR)/pb.c \
$(STACKOPSDIR)/ra.c \
$(STACKOPSDIR)/rb.c \
$(STACKOPSDIR)/rra.c \
$(STACKOPSDIR)/rrb.c \
$(STACKOPSDIR)/sa.c \
$(STACKOPSDIR)/sb.c \
$(SORTDIR)/sort_7.c \
$(SORTDIR)/k_sort.c \
$(HELPERDIR)/utils.c \
push_swap.c

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
