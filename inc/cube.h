/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:29:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/15 11:08:38 by cedmulle         ###   ########.fr       */
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

# define X_RES 1920
# define Y_RES 1080

# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124

# define ROTA_SPEED 0.1
# define MOVE_SPEED 0.1

# define FOV 60

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	orientation;
}			t_player;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*fl;
	void	*cl;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
}			t_mlx;

typedef struct s_settings
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceil;
	bool	fl_ispath;
	bool	cl_ispath;
	int		fl_rgb[3];
	int		cl_rgb[3];
}			t_settings;

typedef struct s_game
{
	int			fd;
	char		*filename;
	char		*filecontent_str;
	size_t		filecontent_size;
	char		**file_tab;
	char		**map;
	char		**map_copy;
	size_t		map_x;
	size_t		map_y;
	t_settings	*settings;
	t_mlx		*mlx;
	t_player	*player;
	t_ray		*ray;
}				t_game;

/* print_data.c */
void	print_data(t_game *game);
/* free.c */
void	free_ptr(void *ptr);
void	free_tab(char **tab);
void	free_data(t_game *game);
/* exit.c */
void	errmsg(const char *errmsg, bool to_free, t_game *game);
void	exit_game(t_game *game);
/* check_args.c */
void	check_args(int argc, char **argv);
char	*remove_spaces(char *str);
/* check_settings.c */
void	check_settings(t_game *game);
/* check_map.c */
void	check_map(t_game *game);
/* check_map_equalizer.c */
void	map_equalizer(t_game *game);
/* check_map_border.c */
void	check_map_border(t_game *game);
/* check_utils.c */
size_t	size_tab(char **tab);
int		tab_size(char **tab);
bool	is_empty_line(char *line);
/* init_data.c */
void	init_data(t_game **game, char **argv);
/* init_rgb.c */
void	init_rgb(t_game *game);
/* init_map.c */
void	parse_map(t_game *game);
void	create_map_copy(t_game **game);
/* init_player.c */
void	init_player(t_game **game);
/* init_rays.c */
void	init_rays(t_game **game);
/* init_mlx.c */
void	init_mlx(t_game *game);
/* main_game.c */
int		main_game(t_game *game);
/* keypress.c */
int		keypress(int keycode, t_game *game);
int		close_window(t_game *game);
/* handle_move.c */
void	move_player(int keycode, t_game *game);
/* move_utils.c */
bool	collision_with_wall(t_game *game, double new_x, double new_y);

#endif
