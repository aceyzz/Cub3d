/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:29:58 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 17:27:30 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	gun(t_game *game)
{
	t_texture	pov;
	int			size_x;
	int			size_y;

	size_x = GUN_X;
	size_y = GUN_Y;
	pov.img = mlx_xpm_file_to_image(game->mlx->mlx, GUN,
			&size_x, &size_y);
	pov.addr = mlx_get_data_addr(pov.img, &pov.bpp, &pov.len, &pov.endian);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, pov.img, X_RES / 4,
		Y_RES - size_y - 30);
	mlx_destroy_image(game->mlx->mlx, pov.img);
}

static void	cursor(t_game *game)
{
	t_texture	pov;
	int			size_x;
	int			size_y;

	size_x = 64;
	size_y = 64;
	pov.img = mlx_xpm_file_to_image(game->mlx->mlx, "./img/bonus/cursor.xpm",
			&size_x, &size_y);
	pov.addr = mlx_get_data_addr(pov.img, &pov.bpp, &pov.len, &pov.endian);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, pov.img, X_RES / 2
		- size_x / 2, Y_RES / 2 - size_y / 2);
	mlx_destroy_image(game->mlx->mlx, pov.img);
}

static void	handle_mouse(t_game *game)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game->mlx->win, &x, &y);
	if (x < X_RES / 2)
		rotate_left(game);
	if (x > X_RES / 2)
		rotate_right(game);
	if (x > X_RES / 2 || x < X_RES / 2)
		mlx_mouse_move(game->mlx->win, X_RES / 2, Y_RES / 2);
}

static int	shoot(int button, int x, int y, t_game *game)
{
	t_texture	pov;
	int			size_x;
	int			size_y;

	size_x = GUN_X;
	size_y = GUN_Y;
	(void)x;
	(void)y;
	if (button == 1)
	{
		pov.img = mlx_xpm_file_to_image(game->mlx->mlx, "./img/bonus/p2.xpm",
				&size_x, &size_y);
		pov.addr = mlx_get_data_addr(pov.img, &pov.bpp, &pov.len, &pov.endian);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, pov.img, X_RES
			/ 4, Y_RES - size_y - 30);
		mlx_destroy_image(game->mlx->mlx, pov.img);
		pov.img = mlx_xpm_file_to_image(game->mlx->mlx, "./img/bonus/p3.xpm",
				&size_x, &size_y);
		pov.addr = mlx_get_data_addr(pov.img, &pov.bpp, &pov.len, &pov.endian);
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, pov.img, X_RES
			/ 4, Y_RES - size_y - 30);
		mlx_destroy_image(game->mlx->mlx, pov.img);
	}
	return (0);
}

void	bonus(t_game *game)
{
	gun(game);
	cursor(game);
	handle_mouse(game);
	mlx_hook(game->mlx->win, 4, 1L << 2, &shoot, game);
}
