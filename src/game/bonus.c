/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:29:58 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/26 08:40:38 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void cursor(t_game *game)
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
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
}


static void	handle_mouse(t_game *game)
{
	int	x;
	int	y;

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
	if (key == 1)
	{
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->gun->img2,
			X_RES / 2 + (X_RES / 8) - game->gun->size_x2 / 2,
			Y_RES - game->gun->size_y2 - 30);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->gun->img3,
			X_RES / 2 + (X_RES / 8) - game->gun->size_x3 / 2,
			Y_RES - game->gun->size_y3 - 30);
	}
	return (0);
}

static void	gun(t_game *game)
{
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->gun->img1,
		X_RES / 2 + (X_RES / 8) - game->gun->size_x1 / 2,
		Y_RES - game->gun->size_y1 - 30);
	mlx_hook(game->mlx->win, 4, 1L << 2, &shoot, game);
}

void	bonus(t_game *game)
{
	cursor(game);
	handle_mouse(game);
	gun(game);
}
