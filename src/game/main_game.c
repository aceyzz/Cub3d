/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:09:43 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/27 18:19:38 by cedmulle         ###   ########.fr       */
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

static void	fill_shade_screen(t_game *game)
{
	int	x;
	int	y;
	int	alpha;
	int	color;

	alpha = 250;
	y = 0;
	color = (alpha << 24) | 0x404040;
	while (y < Y_RES)
	{
		x = 0;
		while (x < X_RES)
		{
			my_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

int	main_game(t_game *game)
{
	if (game->keys->enter == true && game->keys->p == false)
	{
		update_movements(game);
		draw_floor_ceiling(game);
		raycasting(game);
		draw_hud(game);
		minimap(game);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->img, 0, 0);
		bonus(game);
		mlx_mouse_hide();
	}
	if (game->keys->p == true)
	{
		fill_shade_screen(game);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->mlx->img, 0, 0);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->pause->img, 0, 0);
		mlx_mouse_show();
	}
	return (0);
}
