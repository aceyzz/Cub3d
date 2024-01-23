/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:29:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 07:52:08 by cedmulle         ###   ########.fr       */
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

# define MINIMAP_SCALE 10

# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124

# define ROTA_SPEED 0.05
# define MOVE_SPEED 0.05

# define FOV 60
# define TILE_SIZE 50
# define TEX_X 50
# define TEX_Y 50

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_ray
{
	double	camera_x;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	perp_wall_dist;
	int		hit;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_mlx;

typedef struct s_north
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_north;

typedef struct s_south
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_south;

typedef struct s_east
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_east;

typedef struct s_west
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_west;

typedef struct s_floor
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_floor;

typedef struct s_ceil
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_ceil;

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

typedef struct s_minimap
{
	double	line_x;
	double	line_y;
	double	angle;
	double	radius;
	int		color;
}			t_minimap;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}			t_keys;

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
	t_ray		ray[X_RES];
	t_north		*north;
	t_south		*south;
	t_east		*east;
	t_west		*west;
	t_floor		*floor;
	t_ceil		*ceil;
	t_keys		*keys;
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
/* init_textures.c */
void	init_textures(t_game *game);
/* init_map.c */
void	parse_map(t_game *game);
void	create_map_copy(t_game **game);
/* init_player.c */
void	init_player(t_game **game);
/* init_mlx.c */
void	init_mlx(t_game *game);
/* main_game.c */
int		main_game(t_game *game);
/* keypress.c */
int		keypress(int keycode, t_game *game);
int		keyrelease(int keycode, t_game *game);
int		close_window(t_game *game);
/* handle_move.c */
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
/* move_utils.c */
bool	collision_with_wall(t_game *game, double new_x, double new_y);
/* handle_rota.c */
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
/* draw_hud.c */
void	draw_hud(t_game *game);
/* minimap.c */
void	draw_player_minimap(t_game *game);
/* floor_ceiling.c */
void	draw_floor_ceiling(t_game *game);
/* draw_utils.c */
void	my_pixel_put(t_game *game, int x, int y, int color);
int		rgb_to_mlx(int rgb[3]);
/* ray_utils.c */
void	init_rays(t_game *game, t_ray *ray, int x);
void	calculate_line_height(t_game *game, t_ray *ray);
void	set_step(t_game *game, t_ray *ray);
void	set_draw_range(t_ray *ray);
/* raycasting.c */
void	raycasting(t_game *game);

#endif
