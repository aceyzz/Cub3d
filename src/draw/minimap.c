/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/24 13:32:49 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_basis(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 30;
	y = Y_RES - 30 - MINIMAP_SCALE;
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			my_pixel_put(game, x + i, y + j, 0x182258);
			j++;
		}
		i++;
	}
}

static void	draw_frame(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 30;
	y = Y_RES - 30 - MINIMAP_SCALE;
	i = -1;
	while (++i < MINIMAP_SCALE)
	{
		j = -1;
		while (++j < 30)
			my_pixel_put(game, x + i, y + j, 0x202020);
	}
	x = 30 + MINIMAP_SCALE - 15;
	y = Y_RES - 30 - MINIMAP_SCALE;
	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < MINIMAP_SCALE)
			my_pixel_put(game, x + i, y + j, 0x202020);
	}
}

static void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	radius;
	int	i;
	int	j;

	radius = MINIMAP_SCALE / 40;
	x = 30 + MINIMAP_SCALE / 2 - radius;
	y = Y_RES - 30 - MINIMAP_SCALE / 2 + radius * 2;
	i = x - radius;
	while (i < x + radius)
	{
		j = y - radius;
		while (j < y + radius)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
				my_pixel_put(game, i, j, 0xFFFF00);
			j++;
		}
		i++;
	}
}

void	minimap(t_game *game)
{
	draw_basis(game);
	draw_frame(game);
	draw_player(game);
}
