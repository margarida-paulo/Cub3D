# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:37:37 by mvalerio          #+#    #+#              #
#    Updated: 2024/08/20 12:40:53 by plashkar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

STANDARD_FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

MLX_COMPILATION_FLAGS = -I/usr/include -Imlx_linux -O3 -c

MLX_LINK_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MATH_LIB = -lm

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = mlx_linux

SRC = \
	src/main.c \
	src/map.c \
	src/error.c \
	src/test.c \
	src/utils.c \

OBJ = $(SRC:.c=.o)

RED = "\033[31m"
RESET = "\033[0m"
PINK = "\033[35m"
BOLDPINK = "\033[1m\033[35m"
BLINK = "\033[5m"

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) $(MLX_COMPILATION_FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(PINK)"Compiling $@"$(RESET)
	@make -C $(LIBFT_DIR)
	@make -C $(MINILIBX_DIR)
	@$(CC) $(STANDARD_FLAGS) $(MATH_LIB) $(OBJ) $(MLX_LINK_FLAGS) $(LIBFT_A) -o $(NAME)
	@echo $(BLINK)$(BOLDPINK)"Cub3D is ready to run!"$(RESET)

clean:
	@rm -f src/*.o
	@echo $(RED)Object files have been deleted.$(RESET)

fclean: clean
	@rm -f $(LIB)
	@rm -f $(NAME)
	@echo $(RED)"All created files have been deleted."$(RESET)

re: fclean all

v: all clean
	@./$(NAME)

.PHONY: fclean clean all re
