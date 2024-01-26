/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:23:33 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/25 19:59:31 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_mini(t_mini *mini, t_game *game)
{
	mini->index_x = 0;
	mini->index_y = 0;
	mini->offset_x = 30;
	mini->offset_y = Y_RES - MINIMAP_SCALE - 15;
	mini->ratio_x = (double)MINIMAP_SCALE / (double)game->map_x;
	mini->ratio_y = (double)MINIMAP_SCALE / (double)game->map_y;
	mini->size_x = (double)game->map_x * mini->ratio_x;
	mini->size_y = (double)game->map_y * mini->ratio_y * 0.70;
	mini->center_x = mini->offset_x + mini->size_x / 2;
	mini->center_y = mini->offset_y + mini->size_y / 2;
	mini->wall_color = add_shader(0xFFFFFF, 0.80);
	mini->floor_color = add_shader(0xFFFFFF, 0.90);
	mini->empty_color = 0x202020;
}
