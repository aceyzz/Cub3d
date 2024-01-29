/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:23:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/29 14:15:54 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_pause(t_game *game)
{
	game->pause->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/pause.xpm", &game->pause->width,
			&game->pause->height);
	game->pause->addr = mlx_get_data_addr(game->pause->img,
			&game->pause->bpp, &game->pause->len,
			&game->pause->endian);
}

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

void	loading_screen(t_game *game)
{
	sound_effect(SOUNDTRACK);
	game->menu->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/menu.xpm", &game->menu->width, &game->menu->height);
	game->menu->addr = mlx_get_data_addr(game->menu->img,
			&game->menu->bpp, &game->menu->len, &game->menu->endian);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->menu->img, 0, 0);
}

void	init_textures_next(t_game *game)
{
	game->pause = malloc(sizeof(t_texture));
	game->menu = malloc(sizeof(t_texture));
	init_pause(game);
	init_gun_hud(game);
}
