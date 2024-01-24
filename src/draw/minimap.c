/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/24 16:25:52 by cedmulle         ###   ########.fr       */
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

void	minimap(t_game *game)
{
	t_mini	mini;

	draw_basis(game);
	draw_frame(game);
	init_mini(&mini, game);
	render_minimap(game, &mini);
	render_player(game, &mini);
	render_line_direction(game, &mini);
}
