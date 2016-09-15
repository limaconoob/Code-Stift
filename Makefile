# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 09:39:50 by jpepin            #+#    #+#              #
#    Updated: 2016/09/15 12:25:05 by jpepin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I./
LDLIBS = -lft
LDFLAGS = -Llibft/

LIB = libstft.a
NAME = Code-Stift

SRC = main.c \
			coucou_init.c \
			ft_concat.c \
			ft_tri.c \
			ft_signal.c \
			get_next_line.c \
			matrix_init.c \
			stift_cure.c \
			stift_error.c \
			stift_warning.c \
			term_coord.c \
			term_init.c \
			wind_init.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC) -c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

lib:
	@$(CC) $(CPPFLAGS) $(SRC) -c
	@ar rc $(LIB) $(OBJ)

clean:
	@make clean -C ./libft
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
