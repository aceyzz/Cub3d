/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:17:55 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/21 19:06:02 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < X_RES)
	{
		y = Y_RES / 2;
		while (++y < Y_RES)
			my_pixel_put(game, x, y, rgb_to_mlx(game->settings->fl_rgb));
	}
}

static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < X_RES)
	{
		y = -1;
		while (++y < Y_RES / 2)
			my_pixel_put(game, x, y, rgb_to_mlx(game->settings->cl_rgb));
	}
}

void	draw_floor_ceiling(t_game *game)
{
	draw_floor(game);
	draw_ceiling(game);
}
