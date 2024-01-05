# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:47:51 by cedmulle          #+#    #+#              #
#    Updated: 2024/01/05 20:27:30 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRC_DIR = src/
INC_DIR = inc/
SRC		= $(wildcard $(SRC_DIR)*.c)
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -L./$(INC_DIR)mlx -lmlx -framework OpenGL -framework AppKit
RM		= rm -f

all:
	@make -C $(INC_DIR)mlx > /dev/null 2>&1
	@make -C $(INC_DIR)libft > /dev/null 2>&1
	@make $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(INC_DIR)mlx/libmlx.a
	@echo "\033[1;36mMLX ready.\033[0m"
	@echo "\033[1;36mLibft ready.\033[0m"
	@echo "\033[1;36mCub3D ready.\033[0m"
	@echo "\033[1;33m\n\nUsage : ./cub3d <path/to/map.cub>\033[0m"

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
	@echo "\033[1;35mCub3D removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re

norme:
	@python3 -m norminette -R CheckDefine $(SRC) $(INC_DIR)*.h $(INC_DIR)libft/*.c $(INC_DIR)libft/*.h
