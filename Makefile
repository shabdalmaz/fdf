# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/19 19:53:54 by ashabdan          #+#    #+#              #
#    Updated: 2020/03/27 19:26:25 by ashabdan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I.
LIB_LINUX = libft/libft.a -L./minilibx_linux -lmlx -L/usr/lib -lXext -lX11 -lm
LIB_MACOS = libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
SRC = control.c  draw.c  error.c  main.c  reader.c  utils.c menu.c
OBJECTS = $(SRC:.c=.o)
NAME = fdf

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJECTS)
	@make -s -C libft
	@make -s -C minilibx_macos
	@$(CC) $(OBJECTS) $(LIB_MACOS) -o $(NAME)

$(OBJECTS):
	@$(CC) $(CFLAGS) $(SRC)

fclean:	clean
	@rm -rf $(NAME)
	@make -C libft fclean

clean:
	@rm -rf $(OBJECTS)
	@make -C libft clean
	@make -C minilibx_macos clean

re:	fclean all
