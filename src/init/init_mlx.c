/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:02:55 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/17 21:00:05 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_mlx(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		errmsg("Malloc error", true, game);
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
		errmsg("Erreur d'initialisation MLX", true, game);
	game->mlx->win = mlx_new_window(game->mlx->mlx, X_RES, Y_RES, "Cube");
	if (!game->mlx->win)
		errmsg("Erreur de création de la fenêtre", true, game);
	game->mlx->img = mlx_new_image(game->mlx->mlx, X_RES, Y_RES);
	if (!game->mlx->img)
		errmsg("Erreur de création de l'image", true, game);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bpp,
			&game->mlx->len, &game->mlx->endian);
	if (!game->mlx->addr)
		errmsg("Erreur de récupération de l'adresse de l'image", true, game);
}
