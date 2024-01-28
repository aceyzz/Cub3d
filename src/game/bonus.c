/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:29:58 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/28 10:30:49 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cursor(t_game *game)
{
	int	x;
	int	y;

	y = Y_RES / 2;
	x = X_RES / 2 + 10;
	while (x < X_RES / 2 + 25)
		my_pixel_put(game, x++, y, 0x00FF0000);
	x = X_RES / 2 - 10;
	while (x > X_RES / 2 - 25)
		my_pixel_put(game, x--, y, 0x00FF0000);
	x = X_RES / 2;
	y = Y_RES / 2 + 10;
	while (y < Y_RES / 2 + 25)
		my_pixel_put(game, x, y++, 0x00FF0000);
	y = Y_RES / 2 - 10;
	while (y > Y_RES / 2 - 25)
		my_pixel_put(game, x, y--, 0x00FF0000);
	x = X_RES / 2;
	y = Y_RES / 2;
	my_pixel_put(game, x, y, 0x00FF0000);
	my_pixel_put(game, x + 1, y, 0x00FF0000);
	my_pixel_put(game, x - 1, y, 0x00FF0000);
	my_pixel_put(game, x, y + 1, 0x00FF0000);
	my_pixel_put(game, x, y - 1, 0x00FF0000);
}

static void	handle_mouse(t_game *game)
{
	int	x;
	int	y;

	if (game->keys->p == true)
		return ;
	mlx_mouse_get_pos(game->mlx->win, &x, &y);
	if (x < X_RES / 2 - 10)
		rotate_left(game);
	if (x > X_RES / 2 + 10)
		rotate_right(game);
	if (x > X_RES / 2 || x < X_RES / 2)
		mlx_mouse_move(game->mlx->win, X_RES / 2, Y_RES / 2);
}

static int	shoot(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == 1 && game->keys->p == false)
	{
		if (game->gun->ammo > 0)
		{
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->gun->img2, X_RES / 2 + (X_RES / 8) - game->gun->size_x2
				/ 2, Y_RES - game->gun->size_y2 - 35);
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
				game->gun->img3, X_RES / 2 + (X_RES / 8) - game->gun->size_x3
				/ 2, Y_RES - game->gun->size_y3 - 40);
			game->gun->ammo--;
			sound_effect(GUNSHOT);
		}
		else
		{
			sound_effect(DRYSHOT);
			game->gun->empty_mag = true;
		}
	}
	return (0);
}

static void	gun(t_game *game)
{
	if (game->keys->p == true)
		return ;
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->gun->img1,
		X_RES / 2 + (X_RES / 8) - game->gun->size_x1 / 2, Y_RES
		- game->gun->size_y1 - 30);
	mlx_hook(game->mlx->win, 4, 1L << 2, &shoot, game);
	if (game->gun->ammo == 0)
		mlx_string_put(game->mlx->mlx, game->mlx->win, X_RES / 2 + 10, Y_RES / 2
			+ 17, 0x00FF0000, "PRESS R TO RELOAD");
	if (game->keys->r && game->gun->ammo < 7)
	{
		game->gun->ammo = 7;
		game->gun->empty_mag = false;
		sound_effect(RELOAD);
	}
	if (game->keys->e && game->keys->no_auto)
	{
		game->keys->no_auto = false;
		shoot(1, 0, 0, game);
	}
}

void	bonus(t_game *game)
{
	cursor(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
	handle_mouse(game);
	handle_ammos(game);
	gun(game);
}
