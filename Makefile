# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 08:21:10 by aghounam          #+#    #+#              #
#    Updated: 2024/01/03 19:22:14 by aghounam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c ./utils/get_next_line.c ./utils/get_next_line_utils.c \
				checkmap.c ./utils/ft_split.c ./utils/ft_strdup.c  \
				./utils/ft_strtrim.c ./utils/ft_substr.c mouve.c init.c \
				randre.c ./utils/ft_itoa.c error.c
OBJ = $(SRC:.c=.o)
EXEC = so_long
PRINT = printf/libftprintf.a

all: $(PRINT) $(EXEC)

$(PRINT) : printf/Makefile
	@cd printf && make

$(EXEC): $(OBJ)
	@$(CC) $(OBJ) $(PRINT) $(LFLAGS) -o $@

	@echo "\033[4;35m\
                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
	\033[0m"

%.o: %.c solong.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean_printf : printf/Makefile
	@cd printf && make clean

clean: clean_printf
	@echo "all clean"
	@rm -f $(OBJ)

fclean_printf : printf/Makefile
	@cd printf && make fclean	

fclean: clean fclean_printf
	
	@rm -f $(EXEC)

re: fclean all
