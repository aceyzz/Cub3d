/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:09:43 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/26 08:51:00 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	update_movements(t_game *game)
{
	if (game->keys->w)
		move_forward(game);
	if (game->keys->a)
		move_left(game);
	if (game->keys->s)
		move_backward(game);
	if (game->keys->d)
		move_right(game);
	if (game->keys->left)
		rotate_left(game);
	if (game->keys->right)
		rotate_right(game);
	if (game->keys->shift)
		game->player->move_speed = RUN_SPEED;
	if (!game->keys->shift)
		game->player->move_speed = MOVE_SPEED;
}

int	main_game(t_game *game)
{
	update_movements(game);
	draw_floor_ceiling(game);
	raycasting(game);
	draw_hud(game);
	minimap(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
	bonus(game);
	mlx_mouse_hide();
	return (0);
}
