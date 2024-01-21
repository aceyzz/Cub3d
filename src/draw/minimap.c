/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/21 14:29:02 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_player_line(t_game *game)
{
	t_minimap	minimap;
	int			i;

	minimap.line_x = 30 + game->player->pos_x * MINIMAP_SCALE;
	minimap.line_y = Y_RES - 30 - (game->map_y * MINIMAP_SCALE)
		+ game->player->pos_y * MINIMAP_SCALE;
	minimap.angle = atan2(game->player->dir_y, game->player->dir_x);
	minimap.radius = 15;
	minimap.color = 0x00FFFF;
	i = 0;
	while (i < 10)
	{
		minimap.line_x += cos(minimap.angle) * minimap.radius;
		minimap.line_y += sin(minimap.angle) * minimap.radius;
		if (minimap.line_x < 30 || minimap.line_x >= 30 + game->map_x
			* MINIMAP_SCALE || minimap.line_y < Y_RES - 30 - game->map_y
			* MINIMAP_SCALE || minimap.line_y >= Y_RES - 30)
			break ;
		my_pixel_put(game, (int)minimap.line_x, (int)minimap.line_y,
			minimap.color);
		i++;
	}
}

void	draw_player_minimap(t_game *game)
{
	double	minimap_x;
	double	minimap_y;
	double	i;
	double	j;
	double	distance;

	minimap_x = 30 + game->player->pos_x * MINIMAP_SCALE - MINIMAP_SCALE / 2;
	minimap_y = Y_RES - 30 - (game->map_y * MINIMAP_SCALE) + game->player->pos_y
		* MINIMAP_SCALE - MINIMAP_SCALE / 2;
	i = 0.0;
	while (i < MINIMAP_SCALE)
	{
		j = 0.0;
		while (j < MINIMAP_SCALE)
		{
			distance = sqrt(pow(i - MINIMAP_SCALE / 2, 2) + pow(j
						- MINIMAP_SCALE / 2, 2));
			if (distance <= MINIMAP_SCALE / 4)
				my_pixel_put(game, (int)(minimap_x + i), (int)(minimap_y + j),
					0x0000FFFF);
			j += 0.1;
		}
		i += 0.1;
	}
	draw_player_line(game);
}
