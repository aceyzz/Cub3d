/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:48 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/28 11:03:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_top_bottom_border(t_game *game)
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
			my_pixel_put(game, x, y + i, 0x202020);
			my_pixel_put(game, x, Y_RES - 1 - i, 0x202020);
			i++;
		}
		x++;
	}
}

static void	draw_left_right_border(t_game *game)
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
			my_pixel_put(game, x + i, y, 0x202020);
			my_pixel_put(game, X_RES - 1 - i, y, 0x202020);
			i++;
		}
		y++;
	}
}

static void	draw_bottom_right_corner(t_game *game)
{
	int	x;
	int	y;

	y = Y_RES - 30;
	while (y > Y_RES - 30 - 110)
	{
		x = X_RES - 30 - 200;
		while (x < X_RES - 30)
			my_pixel_put(game, x++, y, 0x202020);
		y--;
	}
}

static void	draw_bar_top_right(t_game *game)
{
	int	x;
	int	y;

	y = 29;
	while (++y < 45)
	{
		x = (X_RES - 570) / 2 - 1;
		while (++x < ((X_RES - 570) / 2) + 570)
			my_pixel_put(game, x, y, 0x202020);
	}
}

void	draw_hud(t_game *game)
{
	if (game->keys->enter == true)
	{
		draw_top_bottom_border(game);
		draw_left_right_border(game);
		draw_bottom_right_corner(game);
		draw_bar_top_right(game);
	}
}
