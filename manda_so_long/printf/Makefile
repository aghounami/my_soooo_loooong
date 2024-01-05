# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 13:09:31 by aghounam          #+#    #+#              #
#    Updated: 2023/12/29 08:50:05 by aghounam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDA_SRCS =	ft_printf.c ft_format.c ft_hexa_adress.c ft_hexa_upper.c ft_hexa_lower.c \
				ft_putstr.c ft_putchar.c ft_putnbr.c ft_putpositive.c
NAME = libftprintf.a
CC = cc
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
OBJ = $(MANDA_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIBC) $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean