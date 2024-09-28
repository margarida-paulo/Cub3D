# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:37:37 by mvalerio          #+#    #+#              #
#    Updated: 2024/09/28 16:57:39 by mvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

STANDARD_FLAGS = -Wall -Werror -Wextra -g
MLX_COMPILATION_FLAGS = -I/usr/include -Imlx_linux -O3 -c

MLX_LINK_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MATH_LIB = -lm

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = mlx_linux

SRC = \
	src/main.c \
	src/exit.c \
	src/init.c \
	src/textures.c \
	src/key_press.c \
	src/mini_map_0.c \
	src/mini_map_1.c \
	src/mlx_extra.c \
	src/map.c \
	src/map_setters.c \
	src/map_checks_0.c \
	src/map_checks_1.c \
	src/args.c \
	src/error.c \
	src/test.c \
	src/utils_0.c \
	src/utils_1.c \
	src/free.c \
	src/raycasting.c \
	src/raycasting_utils.c \
	src/rendering.c \
	src/movement.c \
	src/gameplay.c \

OBJ = $(SRC:.c=.o)

RED = "\033[31m"
RESET = "\033[0m"
PINK = "\033[35m"
BOLDPINK = "\033[1m\033[35m"
BLINK = "\033[5m"

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) $(MLX_COMPILATION_FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MINILIBX_DIR)/libmlx_Linux.a
	@echo $(PINK)"Compiling $@"$(RESET)
	@$(CC) $(STANDARD_FLAGS) $(MATH_LIB) $(OBJ) $(MLX_LINK_FLAGS) $(LIBFT_A) -o $(NAME)
	@echo $(BLINK)$(BOLDPINK)"Cub3D is ready to run!"$(RESET)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx_Linux.a:
	@make -C $(MINILIBX_DIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@echo $(RED)Object files have been deleted.$(RESET)

fclean: clean
	@rm -f $(LIB)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo $(RED)"All created files have been deleted."$(RESET)

re: fclean all

v: all clean
	@./$(NAME)

check: clean
	for file in test_maps/invalid_maps/*; do \
		valgrind --leak-check=full ./$(NAME) $$file; \
	done

.PHONY: fclean clean all re v
