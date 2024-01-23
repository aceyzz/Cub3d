/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:43:15 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 09:02:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player->pos_x + (1
					- ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player->pos_y + (1
					- ray->step_y) / 2) / ray->dir_y;
}

static void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int				y;
	unsigned int	color;
	int				tex_x;
	int				tex_y;
	int				end_y;

	y = handling_hud(ray->draw_start, 30, 'm');
	end_y = handling_hud(ray->draw_end, Y_RES - 30, 'l');
	while (y < end_y)
	{
		tex_y = calculate_tex_y(ray, y);
		tex_x = calculate_tex_x(game, ray);
		color = get_texture_color(game, ray, tex_x, tex_y);
		my_pixel_put(game, x, y, color);
		y++;
	}
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < X_RES)
	{
		init_rays(game, &ray, x);
		set_step(game, &ray);
		perform_dda(game, &ray);
		calculate_line_height(game, &ray);
		draw_wall(game, &ray, x);
	}
}
