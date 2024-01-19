/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:25:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/19 10:18:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_textures(t_game *game)
{
	int	size;

	size = 50;
	game->mlx->we = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->west, &size, &size);
	game->mlx->ea = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->east, &size, &size);
	game->mlx->no = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->north, &size, &size);
	game->mlx->so = mlx_xpm_file_to_image(game->mlx->mlx,
			game->settings->south, &size, &size);
	if (!game->mlx->we || !game->mlx->ea || !game->mlx->no || !game->mlx->so)
		errmsg("Texture error NSEW", true, game);
	if (game->settings->fl_ispath)
		game->mlx->fl = mlx_xpm_file_to_image(game->mlx->mlx,
				game->settings->floor, &size, &size);
	if (game->settings->cl_ispath)
		game->mlx->cl = mlx_xpm_file_to_image(game->mlx->mlx,
				game->settings->ceil, &size, &size);
	if (!game->mlx->fl || !game->mlx->cl)
		errmsg("Texture error floor/ceiling", true, game);
}
