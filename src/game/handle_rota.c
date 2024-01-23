/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rota.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:39:16 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 07:58:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rota_speed;

	rota_speed = ROTA_SPEED * 0.5;
	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(rota_speed)
		- game->player->dir_y * sin(rota_speed);
	game->player->dir_y = old_dir_x * sin(rota_speed) + game->player->dir_y
		* cos(rota_speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(rota_speed)
		- game->player->plane_y * sin(rota_speed);
	game->player->plane_y = old_plane_x * sin(rota_speed)
		+ game->player->plane_y * cos(rota_speed);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rota_speed;

	rota_speed = ROTA_SPEED * 0.5;
	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(-rota_speed)
		- game->player->dir_y * sin(-rota_speed);
	game->player->dir_y = old_dir_x * sin(-rota_speed) + game->player->dir_y
		* cos(-rota_speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(-rota_speed)
		- game->player->plane_y * sin(-rota_speed);
	game->player->plane_y = old_plane_x * sin(-rota_speed)
		+ game->player->plane_y * cos(-rota_speed);
}
