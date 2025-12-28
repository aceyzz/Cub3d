# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 18:38:38 by cedmulle          #+#    #+#              #
#    Updated: 2024/01/05 18:45:10 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;36mLibft compiled and ready to use.\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "\033[1;35mLibft cleared.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;35mLibft deleted.\033[0m"

re: fclean all

.PHONY: clean fclean re all

norme:
	@python3 -m norminette -R CheckDefine $(SRC) libft.h
