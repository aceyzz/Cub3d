/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rota.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:39:16 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/17 20:01:00 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(ROTA_SPEED)
		- game->player->dir_y * sin(ROTA_SPEED);
	game->player->dir_y = old_dir_x * sin(ROTA_SPEED)
		+ game->player->dir_y * cos(ROTA_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(ROTA_SPEED)
		- game->player->plane_y * sin(ROTA_SPEED);
	game->player->plane_y = old_plane_x * sin(ROTA_SPEED)
		+ game->player->plane_y * cos(ROTA_SPEED);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(-ROTA_SPEED)
		- game->player->dir_y * sin(-ROTA_SPEED);
	game->player->dir_y = old_dir_x * sin(-ROTA_SPEED)
		+ game->player->dir_y * cos(-ROTA_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(-ROTA_SPEED)
		- game->player->plane_y * sin(-ROTA_SPEED);
	game->player->plane_y = old_plane_x * sin(-ROTA_SPEED)
		+ game->player->plane_y * cos(-ROTA_SPEED);
}

void	rotate_player(int keycode, t_game *game)
{
	if (keycode == K_RIGHT)
		rotate_right(game);
	if (keycode == K_LEFT)
		rotate_left(game);
}
