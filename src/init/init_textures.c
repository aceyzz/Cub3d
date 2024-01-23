/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:25:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 07:59:52 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_nsew(t_game *game)
{
	int	size;

	size = 64;
	game->north->img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->north, &size, &size);
	game->south->img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->south, &size, &size);
	game->east->img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->east, &size, &size);
	game->west->img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->west, &size, &size);
	if (!game->north->img || !game->south->img || !game->east->img
		|| !game->west->img)
		errmsg("Texture error NSEW", true, game);
	game->north->addr = mlx_get_data_addr(game->north->img,
			&game->north->bpp, &game->north->len, &game->north->endian);
	game->south->addr = mlx_get_data_addr(game->south->img,
			&game->south->bpp, &game->south->len, &game->south->endian);
	game->east->addr = mlx_get_data_addr(game->east->img,
			&game->east->bpp, &game->east->len, &game->east->endian);
	game->west->addr = mlx_get_data_addr(game->west->img,
			&game->west->bpp, &game->west->len, &game->west->endian);
}

static void	set_floor(t_game *game)
{
	int	size;

	size = 64;
	game->floor->img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->floor, &size, &size);
	if (!game->floor->img)
		errmsg("Texture error floor", true, game);
	game->floor->addr = mlx_get_data_addr(game->floor->img,
			&game->floor->bpp, &game->floor->len, &game->floor->endian);
}

static void	set_ceil(t_game *game)
{
	int	size;

	size = 64;
	game->ceil->img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->ceil, &size, &size);
	if (!game->ceil->img)
		errmsg("Texture error ceil", true, game);
	game->ceil->addr = mlx_get_data_addr(game->ceil->img,
			&game->ceil->bpp, &game->ceil->len, &game->ceil->endian);
}

void	init_textures(t_game *game)
{
	game->north = malloc(sizeof(t_north));
	game->south = malloc(sizeof(t_south));
	game->east = malloc(sizeof(t_east));
	game->west = malloc(sizeof(t_west));
	if (game->settings->fl_ispath)
		game->floor = malloc(sizeof(t_floor));
	if (game->settings->cl_ispath)
		game->ceil = malloc(sizeof(t_ceil));
	set_nsew(game);
	if (game->settings->fl_ispath)
		set_floor(game);
	if (game->settings->cl_ispath)
		set_ceil(game);
}
