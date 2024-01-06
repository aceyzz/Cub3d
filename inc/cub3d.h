/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:01:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 10:07:47 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

/* ------------------------------ COLORS ------------------------------------ */
# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define GRE	"\033[1;32m"
# define YEL	"\033[1;33m"
# define BLU	"\033[1;34m"
# define MAG	"\033[1;35m"
# define CYA	"\033[1;36m"
# define WHI	"\033[1;37m"

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	bool	is_rgb;
	bool	is_path;
}			t_rgb;

typedef struct s_game
{
	int		fd;
	char	*filename;
	size_t	filesize;
	char	**filecontent;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceil;
	char	**map;
	char	**map_copy;
	t_rgb	rgb[2];
	size_t	mapsize;
}			t_game;

/* error.c */
void	errmsg(const char *errmsg, bool to_free, t_game *game);
void	exit_game(t_game *game);
/* free.c */
void	free_ptr(void *ptr);
void	free_tab(char **tab);
void	free_params(t_game *game);
void	free_data(t_game *game);
/* init.c */
void	print_data(t_game **game);
void	init_struct(t_game **game, char **argv);
/* check.c */
void	check_data(t_game *game);
/* parse_map.c */
void	get_map(t_game *game);
/* parse_file.c */
void	get_filecontent(t_game *game);;
/* parse_param.c */
void	get_params(t_game *game);
/* parse_utils.c */
bool	is_valid_rgb(char *str);
void	trim_fc(t_game *game);
/* check_params.c */
void	check_args(int argc, char **argv);
void	check_nsew(t_game *game);
void	check_rgb_values(t_game *game);
void	check_fc(t_game *game);

#endif
