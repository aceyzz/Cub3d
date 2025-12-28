# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:47:51 by cedmulle          #+#    #+#              #
#    Updated: 2025/12/28 16:23:37 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cube

SRC_DIR = src/
INC_DIR = inc/

# detect de l'OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR = $(INC_DIR)mlx-linux
	MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
	MLX_FLAGS = -I/usr/include -I$(MLX_DIR) -O3
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR = $(INC_DIR)mlx
	MLX_LIB = -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -O3 -ffast-math
	MLX_FLAGS = -I$(MLX_DIR)
endif

SRC_CHK	= $(SRC_DIR)checks/check_args.c \
			$(SRC_DIR)checks/check_map_border.c \
			$(SRC_DIR)checks/check_map_equalizer.c \
			$(SRC_DIR)checks/check_map.c \
			$(SRC_DIR)checks/check_settings.c \
			$(SRC_DIR)checks/check_utils.c

SRC_CLN	= $(SRC_DIR)cleaners/exit.c \
			$(SRC_DIR)cleaners/free.c

SRC_DBG	= $(SRC_DIR)debugs/print_data.c

SRC_DRA	= $(SRC_DIR)draw/draw_utils.c \
			$(SRC_DIR)draw/floor_ceiling.c \
			$(SRC_DIR)draw/hud.c \
			$(SRC_DIR)draw/mini_moving.c \
			$(SRC_DIR)draw/minimap.c

SRC_GAM	= $(SRC_DIR)game/bonus.c \
			$(SRC_DIR)game/bonus_utils.c \
			$(SRC_DIR)game/handle_move.c \
			$(SRC_DIR)game/handle_rota.c \
			$(SRC_DIR)game/keypress.c \
			$(SRC_DIR)game/main_game.c \
			$(SRC_DIR)game/move_utils.c

SRC_INI	= $(SRC_DIR)init/init_data.c \
			$(SRC_DIR)init/init_map.c \
			$(SRC_DIR)init/init_mini.c \
			$(SRC_DIR)init/init_mlx.c \
			$(SRC_DIR)init/init_player.c \
			$(SRC_DIR)init/init_rgb.c \
			$(SRC_DIR)init/init_textures.c \
			$(SRC_DIR)init/init_texture_next.c

SRC_MAI	= $(SRC_DIR)main/main.c

SRC_RAY	= $(SRC_DIR)raycast/raycasting.c \
			$(SRC_DIR)raycast/ray_texture.c \
			$(SRC_DIR)raycast/ray_utils.c

SRC_SOU	= $(SRC_DIR)sounds/sound_effect.c

SRC		= $(SRC_CHK) \
			$(SRC_CLN) \
			$(SRC_DBG) \
			$(SRC_DRA) \
			$(SRC_GAM) \
			$(SRC_INI) \
			$(SRC_MAI) \
			$(SRC_RAY) \
			$(SRC_SOU)

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all:
	@echo "\n     $(BLU)MLX    Compiling ($(UNAME_S))...$(RST)\n"
	@make -C $(MLX_DIR)
	@echo "\n     $(CYA)LIBFT  Compiling...$(RST)\n"
	@make -C $(INC_DIR)libft
	@make $(NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(MLX_LIB)

%.o: %.c
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
	@$(RM) $(OBJ)
	@$(RM) -r ./obj
	@make clean -C $(INC_DIR)libft > /dev/null 2>&1
	@echo "$(MAG)OBJS   Removed √ $(RST)"

fclean: clean
	@$(RM) $(NAME)
	@make clean -C $(MLX_DIR) > /dev/null 2>&1
	@make fclean -C $(INC_DIR)libft > /dev/null 2>&1
	@echo "$(MAG)MLX    Removed √ $(RST)"
	@echo "$(MAG)LIBFT  Removed √ $(RST)"
	@echo "$(MAG)CUBE   Removed √ $(RST)"

re: fclean all

.PHONY: all clean fclean re
