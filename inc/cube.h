/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:29:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/07 15:57:07 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define RST "\033[0m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define MAG "\033[1;35m"
# define CYA "\033[1;36m"
# define WHT "\033[1;37m"

# define x_res 1920
# define y_res 1080

typedef struct s_game
{
	int		fd;
	char	*filename;
	char	*filecontent_str;
	size_t	filecontent_size;
	char	**filecontent_tab;
}			t_game;

/* free.c */
void	free_ptr(void *ptr);
void	free_tab(char **tab);
void	free_data(t_game *game);
/* exit.c */
void	errmsg(const char *errmsg, bool to_free, t_game *game);
void	exit_game(t_game *game);
/* check_args.c */
void	check_args(int argc, char **argv);
/* init_data.c */
void	init_data(t_game **game, char **argv);

#endif
