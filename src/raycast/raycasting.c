/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:43:15 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 07:58:07 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	perform_dda(t_game *game, t_ray *ray)
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

unsigned int	get_texture_color(t_north *north, int x, int y)
{
	int	index;

	while (x >= 50 || y >= 50)
	{
		x -= 50;
		y -= 50;
	}
	index = (y * north->len) + (x * (north->bpp / 8));
	return (*(unsigned int *)(north->addr + index));
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (++y < ray->draw_end)
	{
		if (ray->side == 1)
		{
			if (ray->dir_y < 0)
				my_pixel_put(game, x, y, 0xC74F4F);
			else
				my_pixel_put(game, x, y, 0x4C608E);
		}
		else
		{
			if (ray->dir_x < 0)
				my_pixel_put(game, x, y, 0xC3C74F);
			else
				my_pixel_put(game, x, y, 0x744C8E);
		}
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
