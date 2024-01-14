/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:39:38 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/14 10:46:09 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_ray_position(t_game *game)
{
	game->ray->pos_x = game->player->pos_x;
	game->ray->pos_y = game->player->pos_y;
}

static void	init_ray_orientation_ns(t_game *game)
{
	if (game->player->orientation == 3 * M_PI / 2)
	{
		game->ray->dir_x = 0.0;
		game->ray->dir_y = -1.0;
		game->ray->plane_x = tan(FOV / 2.0 * (M_PI / 180.0));
		game->ray->plane_y = 0.0;
	}
	else if (game->player->orientation == M_PI / 2)
	{
		game->ray->dir_x = 0.0;
		game->ray->dir_y = 1.0;
		game->ray->plane_x = -tan(FOV / 2.0 * (M_PI / 180.0));
		game->ray->plane_y = 0.0;
	}
}

static void	init_ray_orientation_ew(t_game *game)
{
	if (game->player->orientation == 0)
	{
		game->ray->dir_x = 1.0;
		game->ray->dir_y = 0.0;
		game->ray->plane_x = 0.0;
		game->ray->plane_y = tan(FOV / 2.0 * (M_PI / 180.0));
	}
	else if (game->player->orientation == M_PI)
	{
		game->ray->dir_x = -1.0;
		game->ray->dir_y = 0.0;
		game->ray->plane_x = 0.0;
		game->ray->plane_y = -tan(FOV / 2.0 * (M_PI / 180.0));
	}
}

void	init_rays(t_game **game)
{
	(*game)->ray = malloc(sizeof(t_ray));
	if (!(*game)->ray)
		errmsg("Malloc error", true, *game);
	init_ray_position(*game);
	init_ray_orientation_ns(*game);
	init_ray_orientation_ew(*game);
}