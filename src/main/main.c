/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:28:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 16:40:57 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	init_data(&game, argv);
	if (DEBUG == 1)
		print_data(game);
	init_mlx(game);
	init_textures(game);
	draw_hud(game);
	mlx_mouse_move(game->mlx->win, X_RES / 2, Y_RES / 2);
	mlx_loop_hook(game->mlx->mlx, main_game, game);
	mlx_hook(game->mlx->win, 2, 1L << 0, &keypress, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, &keyrelease, game);
	mlx_hook(game->mlx->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx->mlx);
	exit_game(game);
	return (0);
}
