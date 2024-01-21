/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:46:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/21 19:08:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_rays(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)X_RES - 1;
	ray->pos_x = game->player->pos_x;
	ray->pos_y = game->player->pos_y;
	ray->dir_x = game->player->dir_x + game->player->plane_x * ray->camera_x;
	ray->dir_y = game->player->dir_y + game->player->plane_y * ray->camera_x;
	ray->map_x = (int)game->player->pos_x;
	ray->map_y = (int)game->player->pos_y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	ray->side_x = 0;
	ray->side_y = 0;
	ray->perp_wall_dist = 0;
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	calculate_line_height(t_game *game, t_ray *ray)
{
	(void)game;
	ray->line_height = (int)(Y_RES / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + Y_RES / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + Y_RES / 2;
	if (ray->draw_end >= Y_RES)
		ray->draw_end = Y_RES - 1;
}

void	set_draw_range(t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + Y_RES / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + Y_RES / 2;
	if (ray->draw_end >= Y_RES)
		ray->draw_end = Y_RES - 1;
}

void	set_step(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - game->player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - game->player->pos_y) * ray->delta_y;
	}
	set_draw_range(ray);
}
