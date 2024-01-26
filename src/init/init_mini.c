/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:23:33 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/26 10:03:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_gun_hud(t_game *game)
{
	game->gun->e_ammo = mlx_xpm_file_to_image(game->mlx->mlx, E_AMMO,
			&game->gun->e_size_x, &game->gun->e_size_y);
	game->gun->e_addr = mlx_get_data_addr(game->gun->e_ammo, &game->gun->e_bpp,
			&game->gun->e_len, &game->gun->e_endian);
	game->gun->f_ammo = mlx_xpm_file_to_image(game->mlx->mlx, F_AMMO,
			&game->gun->f_size_x, &game->gun->f_size_y);
	game->gun->f_addr = mlx_get_data_addr(game->gun->f_ammo, &game->gun->f_bpp,
			&game->gun->f_len, &game->gun->f_endian);
}

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
	init_gun_hud(game);
}
