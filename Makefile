# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:47:51 by cedmulle          #+#    #+#              #
#    Updated: 2024/01/26 10:47:02 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cube

SRC_DIR = src/
INC_DIR = inc/
SRC		= $(wildcard $(SRC_DIR)checks/*.c) \
			$(wildcard $(SRC_DIR)cleaners/*.c) \
			$(wildcard $(SRC_DIR)debugs/*.c) \
			$(wildcard $(SRC_DIR)draw/*.c) \
			$(wildcard $(SRC_DIR)game/*.c) \
			$(wildcard $(SRC_DIR)init/*.c) \
			$(wildcard $(SRC_DIR)main/*.c) \
			$(wildcard $(SRC_DIR)raycast/*.c)
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -L./$(INC_DIR)mlx -lmlx -framework OpenGL -framework AppKit -O3 -ffast-math
RM		= rm -f

NB		= $(words $(SRC))
COUNTER	= 0

RST		= \033[0m
RED		= \033[1;31m
GRE		= \033[1;32m
YEL		= \033[1;33m
BLU		= \033[1;34m
MAG		= \033[1;35m
CYA		= \033[1;36m
WHI		= \033[1;37m
D_RED	= \033[0;31m
D_GRE	= \033[0;32m
D_YEL	= \033[0;33m
D_BLU	= \033[0;34m
D_MAG	= \033[0;35m
D_CYA	= \033[0;36m
D_WHI	= \033[0;37m

define loading_bar
	@CURRENT=$$(( ($1) * 50 / $(NB) )); \
	TOTAL=50; \
	LOADING_BAR="["; \
	for i in $$(seq 1 $$CURRENT); do LOADING_BAR=$$LOADING_BAR"$(GRE)█$(RST)"; done; \
	for i in $$(seq $$CURRENT $$TOTAL); do LOADING_BAR=$$LOADING_BAR" "; done; \
	LOADING_BAR=$$LOADING_BAR"]"; \
	echo -ne "\033[K\r$$LOADING_BAR $$((CURRENT * 2))% Complete";
endef

define start_ft
	echo "\n"
	echo "     $(D_GRE)##########$(GRE)--                                               $(GRE)-$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)----                                           $(GRE)---$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------                                      $(GRE)------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##                                  $(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)--                            $(GRE)--$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)########################$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)########################$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#######           ######$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)######             #####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#####               ####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#####               ####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#####               ####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#####               ####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#####               ####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)----$(D_GRE)#####               ####$(GRE)----$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##$(GRE)--                            $(GRE)--$(D_GRE)##$(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)------$(D_GRE)##                                  $(GRE)--------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)-----                                       $(GRE)------$(D_GRE)##########$(RST)"
	echo "     $(D_GRE)##########$(GRE)---                                            $(GRE)---$(D_GRE)##########$(RST)"
	echo "\n"
	echo "                      $(D_GRE)██████ ██    ██ ██████  ██████  ██████$(RST)"
	echo "                     $(D_GRE)██      ██    ██ ██   ██      ██ ██   ██$(RST)"
	echo "                     $(GRE)██      ██    ██ ██████   █████  ██   ██$(RST)"
	echo "                     $(D_GRE)██      ██    ██ ██   ██      ██ ██   ██$(RST)"
	echo "                      $(D_GRE)██████  ██████  ██████  ██████  ██████$(RST)"
	echo "\n"
	echo "                                   $(BLU)MLX    $(BLU)Ready $(GRE)√ $(RST)"
	echo "                                   $(BLU)LIBFT  $(BLU)Ready $(GRE)√ $(RST)"
	echo "                                   $(RED)CUBE   $(RED)Ready $(GRE)√ $(RST)"
	echo "\n"
	echo "                  ------------------------------------------------$(RST)"
	echo "                           $(YEL)Usage: ./cube <path/to/map.cub>$(RST)"
	echo "                  ------------------------------------------------$(RST)"
	echo "\n"
endef

all:
	@clear
	@echo "\n     $(BLU)MLX    Compiling...$(RST)\n"
	@make -C $(INC_DIR)mlx > /dev/null 2>&1
	@clear
	@echo "\n     $(CYA)LIBFT  Compiling...$(RST)\n"
	@make -C $(INC_DIR)libft > /dev/null 2>&1
	@clear
	@make $(NAME)
	@mkdir -p ./obj
	@mv $(OBJ) ./obj

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ) $(INC_DIR)libft/libft.a $(INC_DIR)mlx/libmlx.a
	@clear
	@$(call start_ft)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
	@clear
	@$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	@$(call loading_bar,$(COUNTER))
	@echo "$(RST)"

clean:
	@$(RM) $(OBJ)
	@$(RM) -r ./obj
	@make clean -C $(INC_DIR)libft > /dev/null 2>&1
	@echo "$(MAG)OBJS   Removed √ $(RST)"

fclean: clean
	@$(RM) $(NAME)
	@make clean -C $(INC_DIR)mlx > /dev/null 2>&1
	@make fclean -C $(INC_DIR)libft > /dev/null 2>&1
	@echo "$(MAG)MLX    Removed √ $(RST)"
	@echo "$(MAG)LIBFT  Removed √ $(RST)"
	@echo "$(MAG)CUBE   Removed √ $(RST)"

re: fclean all

.PHONY: all clean fclean re

norme:
	@python3 -m norminette -R CheckDefine $(SRC) $(INC_DIR)*.h $(INC_DIR)libft/*.c $(INC_DIR)libft/*.h | sed "s/Error/[1;31m&/; s/line:/[0m&/; s/$$/[0m/; s/OK!/[1;32m&/; s/KO/[1;31m&/; s/(/[0m&/"
	@echo "\n$(GRE)---------------------------------$(RST)\n"
	@python3 -m norminette -R CheckDefine $(SRC) $(INC_DIR)*.h $(INC_DIR)libft/*.c $(INC_DIR)libft/*.h | awk '/^Error:/ {errorCount++} /OK/ {count++} END {total = NR - errorCount; if (count == total) {print "\033[1;32m\tOK: " count " / " total " total\033[0m"} else {print "\033[1;31m\tKO: " count " / " total " total\033[0m"}}'
	@echo "\n$(GRE)---------------------------------$(RST)\n"
