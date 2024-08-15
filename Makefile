# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maggie <maggie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:37:37 by mvalerio          #+#    #+#              #
#    Updated: 2024/08/15 11:45:55 by maggie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

STANDARD_FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

LIB = ${NAME}.a

SRC = \
	src/main.c

OBJ = $(SRC:.c=.o)

RED = "\033[31m"
RESET = "\033[0m"
PINK = "\033[35m"
BOLDPINK = "\033[1m\033[35m"
BLINK = "\033[5m"

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(PINK)"Compiling $@"$(RESET)
	@$(CC) $(STANDARD_FLAGS) $(INCLUDE) $(OBJ) -o $(NAME) > /dev/null
	@echo $(BLINK)$(BOLDPINK)"Cub3D is ready to run!"$(RESET)

$(LIB): $(OBJ)
	@echo $(PINK)"Creating $@"$(RESET)
	@ar rcs $(LIB) $(OBJ)
	@echo $(PINK)The library $(LIB) has been created.$(RESET)

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
