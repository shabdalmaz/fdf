# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashabdan <ashabdan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/19 19:53:54 by ashabdan          #+#    #+#              #
#    Updated: 2020/10/05 21:48:11 by ashabdan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Werror -Wextra
MLX_FLAGS := -framework OpenGL -framework AppKit
NAME := fdf

INC_DIR := ./includes/
SRC_DIR := ./srcs/
OBJ_DIR := ./objs/
LIBFT := ./libs/libft/
MLX := ./libs/minilibx_macos/

SRCS := $(wildcard $(addsuffix *.c, $(SRC_DIR)))
OBJS := $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRCS:.c=.o))
LIBS := $(addsuffix libft.a, $(LIBFT)) $(addsuffix libmlx.a, $(MLX)) $(MLX_FLAGS)

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT)
	@make -s -C $(MLX)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -o $@ -c $^ $(CFLAGS) -I $(INC_DIR)

fclean:	clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean

re:	fclean all
