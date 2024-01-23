/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:55 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 10:04:29 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_texture_pixel_fl(t_game *game, int x, int y)
{
	t_floor_ceiling	fc;
	int				p;
	double			pos_z;
	int				tex_x;
	int				tex_y;

	p = y - Y_RES / 2;
	pos_z = 0.5 * Y_RES;
	fc.dir_x_a = game->player->dir_x - game->player->plane_x;
	fc.dir_y_a = game->player->dir_y - game->player->plane_y;
	fc.dir_x_b = game->player->dir_x + game->player->plane_x;
	fc.dir_y_b = game->player->dir_y + game->player->plane_y;
	fc.dir_row = pos_z / p;
	fc.step_x = fc.dir_row * (fc.dir_x_b - fc.dir_x_a) / X_RES;
	fc.step_y = fc.dir_row * (fc.dir_y_b - fc.dir_y_a) / X_RES;
	fc.floor_x = game->player->pos_x + fc.dir_row * fc.dir_x_a;
	fc.floor_y = game->player->pos_y + fc.dir_row * fc.dir_y_a;
	fc.floor_x += fc.step_x * x;
	fc.floor_y += fc.step_y * x;
	tex_x = (int)(fc.floor_x * TEX_SIZE) % TEX_SIZE;
	tex_y = (int)(fc.floor_y * TEX_SIZE) % TEX_SIZE;
	my_pixel_put(game, x, y, get_texture_color_fc(game, 'F', tex_x, tex_y));
}

static void	draw_texture_pixel_cl(t_game *game, int x, int y)
{
	t_floor_ceiling	fc;
	int				p;
	int				tex_x;
	int				tex_y;
	double			pos_z;

	pos_z = 0.5 * Y_RES;
	fc.dir_x_a = game->player->dir_x - game->player->plane_x;
	fc.dir_y_a = game->player->dir_y - game->player->plane_y;
	fc.dir_x_b = game->player->dir_x + game->player->plane_x;
	fc.dir_y_b = game->player->dir_y + game->player->plane_y;
	p = Y_RES / 2 - y;
	fc.dist_wall = pos_z / p;
	fc.step_x = fc.dist_wall * (fc.dir_x_b - fc.dir_x_a) / X_RES;
	fc.step_y = fc.dist_wall * (fc.dir_y_b - fc.dir_y_a) / X_RES;
	fc.floor_x = game->player->pos_x + fc.dist_wall * fc.dir_x_a;
	fc.floor_y = game->player->pos_y + fc.dist_wall * fc.dir_y_a;
	fc.floor_x += fc.step_x * x;
	fc.floor_y += fc.step_y * x;
	tex_x = (int)(fc.floor_x * TEX_SIZE) % TEX_SIZE;
	tex_y = (int)(fc.floor_y * TEX_SIZE) % TEX_SIZE;
	my_pixel_put(game, x, y, get_texture_color_fc(game, 'C', tex_x, tex_y));
}

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	x = 29;
	while (++x < X_RES - 30)
	{
		y = Y_RES / 2 - 29;
		while (++y < Y_RES - 30)
		{
			if (game->settings->fl_ispath == false)
				my_pixel_put(game, x, y, rgb_to_mlx(game->settings->fl_rgb));
			else
				draw_texture_pixel_fl(game, x, y);
		}
	}
}

static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	x = 29;
	while (++x < X_RES - 30)
	{
		y = 29;
		while (++y < Y_RES / 2 - 30)
		{
			if (game->settings->cl_ispath == false)
				my_pixel_put(game, x, y, rgb_to_mlx(game->settings->cl_rgb));
			else
				draw_texture_pixel_cl(game, x, y);
		}
	}
}

void	draw_floor_ceiling(t_game *game)
{
	draw_floor(game);
	draw_ceiling(game);
}
