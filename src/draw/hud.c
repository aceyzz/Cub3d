/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:48 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/17 21:30:25 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_top_bottom_border(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	while (x < X_RES)
	{
		i = 0;
		while (i < 30)
		{
			my_pixel_put(game, x, y + i, 0x00333333);
			my_pixel_put(game, x, Y_RES - 1 - i, 0x00333333);
			i++;
		}
		x++;
	}
}

void	draw_left_right_border(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	while (y < Y_RES)
	{
		i = 0;
		while (i < 30)
		{
			my_pixel_put(game, x + i, y, 0x00333333);
			my_pixel_put(game, X_RES - 1 - i, y, 0x00333333);
			i++;
		}
		y++;
	}
}

void	draw_minimap_square(t_game *game, size_t x, size_t y, int color)
{
	size_t	minimap_x;
	size_t	minimap_y;
	size_t	i;
	size_t	j;

	minimap_x = 30 + x * MINIMAP_SCALE;
	minimap_y = Y_RES - 30 - (game->map_y * MINIMAP_SCALE) + y * MINIMAP_SCALE;
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			my_pixel_put(game, minimap_x + i, minimap_y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game->map_x)
	{
		y = 0;
		draw_minimap_square(game, x, y - 1, 0x00333333);
		while (y < game->map_y)
		{
			if (game->map[y][x] == '1')
				draw_minimap_square(game, x, y, 0x00000066);
			else if (game->map[y][x] != ' ' && game->map[y][x] != '0')
				draw_minimap_square(game, x, y, 0x0000FFFF);
			else
				draw_minimap_square(game, x, y, 0x00333333);
			y++;
		}
		x++;
	}
	y = -1;
	while (++y <= game->map_y)
		draw_minimap_square(game, x, y - 1, 0x00333333);
}

void	draw_hud(t_game *game)
{
	draw_top_bottom_border(game);
	draw_left_right_border(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
}
