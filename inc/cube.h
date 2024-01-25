/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:29:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/25 21:02:49 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define DEBUG 1

# define RST "\033[0m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define MAG "\033[1;35m"
# define CYA "\033[1;36m"
# define WHT "\033[1;37m"

# define X_RES 1280
# define Y_RES 720

# define MINIMAP_SCALE 150
# define MINIMAP_RANGE 4

# define GUN_A "./img/bonus/1.xpm"
# define GUN_B "./img/bonus/2.xpm"
# define GUN_C "./img/bonus/3.xpm"

# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124

# define ROTA_SPEED 0.12
# define MOVE_SPEED 0.11

# define FOV 60
# define TEX_SIZE 128

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rota_speed;
}				t_player;

typedef struct s_ray
{
	double		camera_x;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	double		perp_wall_dist;
	int			hit;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_mini
{
	size_t		index_x;
	size_t		index_y;
	size_t		center_x;
	size_t		center_y;
	int			offset_x;
	int			offset_y;
	size_t		size_x;
	size_t		size_y;
	double		ratio_x;
	double		ratio_y;
	int			wall_color;
	int			floor_color;
	int			empty_color;
}				t_mini;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_texture;

typedef struct s_gun
{
	void		*img1;
	char		*addr1;
	int			bpp1;
	int			len1;
	int			endian1;
	int			size_x1;
	int			size_y1;
	void		*img2;
	char		*addr2;
	int			bpp2;
	int			len2;
	int			endian2;
	int			size_x2;
	int			size_y2;
	void		*img3;
	char		*addr3;
	int			bpp3;
	int			len3;
	int			endian3;
	int			size_x3;
	int			size_y3;
	void		*img4;
	char		*addr4;
	int			bpp4;
	int			len4;
	int			endian4;
	int			size_x4;
	int			size_y4;
}				t_gun;

typedef struct s_tex_utils
{
	double		dist_wall;
	double		current_dist;
	double		weight;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
	double		current_ceiling_x;
	double		current_ceiling_y;
	int			ceiling_tex_x;
	int			ceiling_tex_y;
}				t_tex_utils;

typedef struct s_floor_ceiling
{
	double		dir_x_a;
	double		dir_y_a;
	double		dir_x_b;
	double		dir_y_b;
	double		dir_row;
	double		step_x;
	double		step_y;
	double		floor_x;
	double		floor_y;
	double		dist_wall;
}				t_floor_ceiling;

typedef struct t_tools
{
	int			x;
	int			y;
	int			mirrored_y;
	double		dist_wall;
	double		dist_floor;
}				t_tools;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_mlx;

typedef struct s_north
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_north;

typedef struct s_south
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_south;

typedef struct s_east
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_east;

typedef struct s_west
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_west;

typedef struct s_floor
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_floor;

typedef struct s_ceil
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_ceil;

typedef struct s_settings
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*floor;
	char		*ceil;
	bool		fl_ispath;
	bool		cl_ispath;
	int			fl_rgb[3];
	int			cl_rgb[3];
}				t_settings;

typedef struct s_keys
{
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		left;
	bool		right;
}				t_keys;

typedef struct s_game
{
	int			fd;
	int			frame;
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
	t_gun		*gun;
}				t_game;

/* print_data.c */
void			print_data(t_game *game);
/* free.c */
void			free_ptr(void *ptr);
void			free_tab(char **tab);
void			free_data(t_game *game);
/* exit.c */
void			errmsg(const char *errmsg, bool to_free, t_game *game);
void			exit_game(t_game *game);
/* check_args.c */
void			check_args(int argc, char **argv);
char			*remove_spaces(char *str);
/* check_settings.c */
void			check_settings(t_game *game);
/* check_map.c */
void			check_map(t_game *game);
/* check_map_equalizer.c */
void			map_equalizer(t_game *game);
/* check_map_border.c */
void			check_map_border(t_game *game);
/* check_utils.c */
size_t			size_tab(char **tab);
int				tab_size(char **tab);
bool			is_empty_line(char *line);
/* init_data.c */
void			init_data(t_game **game, char **argv);
/* init_rgb.c */
void			init_rgb(t_game *game);
/* init_textures.c */
void			init_textures(t_game *game);
/* init_map.c */
void			parse_map(t_game *game);
void			create_map_copy(t_game **game);
/* init_player.c */
void			init_player(t_game **game);
/* init_mlx.c */
void			init_mlx(t_game *game);
/* main_game.c */
int				main_game(t_game *game);
/* keypress.c */
int				keypress(int keycode, t_game *game);
int				keyrelease(int keycode, t_game *game);
int				close_window(t_game *game);
/* handle_move.c */
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
/* move_utils.c */
bool			collision_with_wall(t_game *game, double new_x, double new_y);
/* handle_rota.c */
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
/* draw_hud.c */
void			draw_hud(t_game *game);
/* floor_ceiling.c */
void			draw_floor_ceiling(t_game *game);
/* draw_utils.c */
void			my_pixel_put(t_game *game, int x, int y, int color);
int				rgb_to_mlx(int rgb[3]);
int				add_shader(int color, double distance);
/* ray_utils.c */
void			init_rays(t_game *game, t_ray *ray, int x);
void			calculate_line_height(t_game *game, t_ray *ray);
void			set_step(t_game *game, t_ray *ray);
void			set_draw_range(t_ray *ray);
int				handling_hud(int a, int b, char c);
/* raycasting.c */
void			raycasting(t_game *game);
/* ray_texture.c */
int				get_texture_color_fc(t_game *game, char fc, int tex_x,
					int tex_y);
int				get_texture_color(t_game *game, t_ray *ray, int tex_x,
					int tex_y);
int				calculate_tex_x(t_game *game, t_ray *ray);
int				calculate_tex_y(t_ray *ray, int y);
/* bonus.c */
void			bonus(t_game *game);
void			minimap(t_game *game);
/* init_mini.c */
void			init_mini(t_mini *mini, t_game *game);
/* mini_moving.c */
void			render_minimap(t_game *game, t_mini *mini);
void			render_player(t_game *game, t_mini *mini);
void			render_line_direction(t_game *game, t_mini *mini);

#endif

/*

    Noir:		0x000000
    Blanc:		0xFFFFFF
    Rouge:		0xFF0000
    Vert:		0x008000
    Bleu:		0x0000FF
    Jaune:		0xFFFF00
    Cyan:		0x00FFFF
    Magenta:	0xFF00FF
    Argent:		0xC0C0C0
    Gris: 		0x808080
    Maroon:		0x800000
    Olive:		0x808000
    Vert foncé:	0x008080
    Pourpre:	0x800080
    Teal:		0x008080
    Navy: 		0x000080

*/