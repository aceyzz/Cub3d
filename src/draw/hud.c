/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:48 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/24 16:13:50 by cedmulle         ###   ########.fr       */
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

void	draw_hud(t_game *game)
{
	draw_top_bottom_border(game);
	draw_left_right_border(game);
}
