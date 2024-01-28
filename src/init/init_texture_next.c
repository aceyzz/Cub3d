/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:23:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/28 11:47:58 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_health_minigun_skin(t_game *game)
{
	game->health->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/health.xpm", &game->health->width,
			&game->health->height);
	game->health->addr = mlx_get_data_addr(game->health->img,
			&game->health->bpp, &game->health->len,
			&game->health->endian);
	game->minigun->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/minigun.xpm", &game->minigun->width,
			&game->minigun->height);
	game->minigun->addr = mlx_get_data_addr(game->minigun->img,
			&game->minigun->bpp, &game->minigun->len,
			&game->minigun->endian);
	game->skin->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/skin.xpm", &game->skin->width,
			&game->skin->height);
	game->skin->addr = mlx_get_data_addr(game->skin->img,
			&game->skin->bpp, &game->skin->len,
			&game->skin->endian);
}

static void	init_pause(t_game *game)
{
	game->pause->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/pause.xpm", &game->pause->width,
			&game->pause->height);
	game->pause->addr = mlx_get_data_addr(game->pause->img,
			&game->pause->bpp, &game->pause->len,
			&game->pause->endian);
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
	game->health = malloc(sizeof(t_texture));
	game->minigun = malloc(sizeof(t_texture));
	game->pause = malloc(sizeof(t_texture));
	game->menu = malloc(sizeof(t_texture));
	game->skin = malloc(sizeof(t_texture));
	init_health_minigun_skin(game);
	init_pause(game);
}
