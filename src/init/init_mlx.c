/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:02:55 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/14 11:33:52 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	keypress(int keycode, t_game *game)
{
	printf("\033[1;31m%d\033[0m key pressed\n", keycode);
	if (keycode == K_ESC)
		exit_game(game);
	return (0);
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}

void	multi_hooks(t_game *game)
{
	mlx_hook(game->mlx->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->mlx->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx->mlx);
}

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
	multi_hooks(game);
}
