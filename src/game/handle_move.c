/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:38:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/17 19:49:20 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos_x + MOVE_SPEED * game->player->dir_x;
	new_y = game->player->pos_y + MOVE_SPEED * game->player->dir_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos_x - MOVE_SPEED * game->player->dir_x;
	new_y = game->player->pos_y - MOVE_SPEED * game->player->dir_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos_x - MOVE_SPEED * game->player->plane_x;
	new_y = game->player->pos_y - MOVE_SPEED * game->player->plane_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos_x + MOVE_SPEED * game->player->plane_x;
	new_y = game->player->pos_y + MOVE_SPEED * game->player->plane_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == K_W)
		move_forward(game);
	if (keycode == K_A)
		move_left(game);
	if (keycode == K_S)
		move_backward(game);
	if (keycode == K_D)
		move_right(game);
}
