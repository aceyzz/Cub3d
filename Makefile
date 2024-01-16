# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:47:51 by cedmulle          #+#    #+#              #
#    Updated: 2024/01/16 17:38:29 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cube

SRC_DIR = src/
INC_DIR = inc/
SRC		= $(wildcard $(SRC_DIR)checks/*.c) \
			$(wildcard $(SRC_DIR)cleaners/*.c) \
			$(wildcard $(SRC_DIR)debugs/*.c) \
			$(wildcard $(SRC_DIR)game/*.c) \
			$(wildcard $(SRC_DIR)init/*.c) \
			$(wildcard $(SRC_DIR)main/*.c)
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -L./$(INC_DIR)mlx -lmlx -framework OpenGL -framework AppKit -O3 -ffast-math
RM		= rm -f

all:
	@make -C $(INC_DIR)mlx > /dev/null 2>&1
	@make -C $(INC_DIR)libft > /dev/null 2>&1
	@make $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(INC_DIR)mlx/libmlx.a
	@echo "\033[1;36mMLX ready.\033[0m"
	@echo "\033[1;36mLibft ready.\033[0m"
	@echo "\033[1;36mCube ready.\033[0m"
	@echo "\033[1;33m\n\nUsage : ./cube <path/to/map.cub>\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
	@$(RM) $(OBJ)
	@make clean -C $(INC_DIR)libft > /dev/null 2>&1
	@make clean -C $(INC_DIR)mlx > /dev/null 2>&1
	@echo "\033[1;35mObjects removed.\033[0m"
	@echo "\033[1;35mMinilibx removed.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(INC_DIR)libft > /dev/null 2>&1
	@echo "\033[1;35mLibft removed.\033[0m"
	@echo "\033[1;35mCube removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re

norme:
	@python3 -m norminette -R CheckDefine $(SRC) $(INC_DIR)*.h $(INC_DIR)libft/*.c $(INC_DIR)libft/*.h | sed "s/Error/[1;31m&/; s/line:/[0m&/; s/$$/[0m/; s/OK!/[1;32m&/; s/KO/[1;31m&/; s/(/[0m&/"
