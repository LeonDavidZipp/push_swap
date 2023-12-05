# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 19:14:44 by lzipp             #+#    #+#              #
#    Updated: 2023/12/05 10:57:41 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

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
$(HELPERDIR)/ft_strncmp.c \
$(HELPERDIR)/ft_strdup.c \
$(HELPERDIR)/ft_strlen.c \
$(HELPERDIR)/ft_strsepjoin.c \
$(HELPERDIR)/ft_substr.c \
$(HELPERDIR)/ft_sqrt.c \
$(HELPERDIR)/utils.c \
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
push_swap.c

OBJECTS = $(SOURCES:.c=.o)

BONUSDIR = ./bonus
NEXTLINEDIR = /get_next_line
BONUS_SOURCES = \
$(BONUSDIR)/checker.c \
$(BONUSDIR)/execute_commands.c \
$(BONUSDIR)$(NEXTLINEDIR)/get_next_line_utils_bonus.c \
$(BONUSDIR)$(NEXTLINEDIR)/get_next_line_bonus.c \
$(STACKOPSDIR)/pa.c \
$(STACKOPSDIR)/pb.c \
$(STACKOPSDIR)/ra.c \
$(STACKOPSDIR)/rb.c \
$(STACKOPSDIR)/rra.c \
$(STACKOPSDIR)/rrb.c \
$(STACKOPSDIR)/sa.c \
$(STACKOPSDIR)/sb.c \
$(STACKOPSDIR)/make_stack_a.c \
$(STACKOPSDIR)/make_stack_b.c \
$(HELPERDIR)/ft_atol.c \
$(HELPERDIR)/ft_isdigit.c \
$(HELPERDIR)/ft_memmove.c \
$(HELPERDIR)/ft_split.c \
$(HELPERDIR)/ft_strcmp.c \
$(HELPERDIR)/ft_strncmp.c \
$(HELPERDIR)/ft_strdup.c \
$(HELPERDIR)/ft_strsepjoin.c \
$(HELPERDIR)/ft_sqrt.c \
$(HELPERDIR)/utils.c \

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)
	
bonus: $(BONUS_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

cm: bonus clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re cm
