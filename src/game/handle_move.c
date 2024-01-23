/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:38:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 07:58:20 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	normalize_speed(double *dx, double *dy)
{
	double	norm;

	norm = sqrt((*dx) * (*dx) + (*dy) * (*dy));
	if (norm > 0)
	{
		*dx /= norm;
		*dy /= norm;
	}
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->dir_x;
	new_y = game->player->dir_y;
	normalize_speed(&new_x, &new_y);
	new_x = game->player->pos_x + MOVE_SPEED * new_x;
	new_y = game->player->pos_y + MOVE_SPEED * new_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = -game->player->dir_x;
	new_y = -game->player->dir_y;
	normalize_speed(&new_x, &new_y);
	new_x = game->player->pos_x + MOVE_SPEED * new_x;
	new_y = game->player->pos_y + MOVE_SPEED * new_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = -game->player->plane_x;
	new_y = -game->player->plane_y;
	normalize_speed(&new_x, &new_y);
	new_x = game->player->pos_x + MOVE_SPEED * new_x;
	new_y = game->player->pos_y + MOVE_SPEED * new_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player->plane_x;
	new_y = game->player->plane_y;
	normalize_speed(&new_x, &new_y);
	new_x = game->player->pos_x + MOVE_SPEED * new_x;
	new_y = game->player->pos_y + MOVE_SPEED * new_y;
	if (!collision_with_wall(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
}
