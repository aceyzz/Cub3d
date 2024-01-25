/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_moving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:24:20 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/25 19:58:42 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_square(t_game *game, t_mini *mini, int color)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = mini->offset_x + mini->index_x * mini->ratio_x;
	y = mini->offset_y + mini->index_y * mini->ratio_y;
	i = x;
	while (i < x + mini->ratio_x)
	{
		j = y;
		while (j < y + mini->ratio_y)
		{
			my_pixel_put(game, i, j, color);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_game *game, t_mini *mini)
{
	while (mini->index_y < game->map_y)
	{
		mini->index_x = 0;
		while (mini->index_x < game->map_x)
		{
			if (game->map[mini->index_y][mini->index_x] == '1')
				draw_square(game, mini, mini->wall_color);
			else if (game->map[mini->index_y][mini->index_x] == '0'
				|| game->map[mini->index_y][mini->index_x] == 'N'
				|| game->map[mini->index_y][mini->index_x] == 'S'
				|| game->map[mini->index_y][mini->index_x] == 'E'
				|| game->map[mini->index_y][mini->index_x] == 'W')
				draw_square(game, mini, mini->floor_color);
			else
				draw_square(game, mini, mini->empty_color);
			mini->index_x++;
		}
		mini->index_y++;
	}
}

void	render_player(t_game *game, t_mini *mini)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = mini->offset_x + game->player->pos_x * mini->ratio_x;
	y = mini->offset_y + game->player->pos_y * mini->ratio_y;
	i = x - 5;
	while (i < x + 3)
	{
		j = y - 3;
		while (j < y + 3)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= 3 * 3)
				my_pixel_put(game, i, j, add_shader(0xFF0000, 0.40));
			j++;
		}
		i++;
	}
}

void	render_line_direction(t_game *game, t_mini *mini)
{
	int	x;
	int	y;
	int	i;

	x = mini->offset_x + game->player->pos_x * mini->ratio_x;
	y = mini->offset_y + game->player->pos_y * mini->ratio_y;
	i = 0;
	while (++i < 10)
	{
		my_pixel_put(game, x + i * game->player->dir_x, y + i
			* game->player->dir_y, add_shader(0xFF0000, 0.40));
	}
}
