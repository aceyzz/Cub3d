/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:38:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/15 11:25:21 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->pos_x + MOVE_SPEED * cos(game->player->orientation);
	new_y = game->player->pos_y + MOVE_SPEED * sin(game->player->orientation);
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

	new_x = game->player->pos_x - MOVE_SPEED * cos(game->player->orientation);
	new_y = game->player->pos_y - MOVE_SPEED * sin(game->player->orientation);
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

	new_x = game->player->pos_x - MOVE_SPEED * cos(game->player->orientation
			+ M_PI_2);
	new_y = game->player->pos_y - MOVE_SPEED * sin(game->player->orientation
			+ M_PI_2);
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

	new_x = game->player->pos_x + MOVE_SPEED * cos(game->player->orientation
			+ M_PI_2);
	new_y = game->player->pos_y + MOVE_SPEED * sin(game->player->orientation
			+ M_PI_2);
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
