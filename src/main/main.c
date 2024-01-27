/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:28:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/27 19:43:00 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	loading_screen(t_game *game)
{
	if (fork() == 0)
		execl("/usr/bin/afplay", "afplay", "./sound/soundtrack.mp3", NULL);
	game->menu->img = mlx_xpm_file_to_image(game->mlx->mlx,
			"./img/bonus/menu.xpm", &game->menu->width, &game->menu->height);
	game->menu->addr = mlx_get_data_addr(game->menu->img,
			&game->menu->bpp, &game->menu->len, &game->menu->endian);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->menu->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	init_data(&game, argv);
	if (DEBUG == 1)
		print_data(game);
	init_mlx(game);
	init_textures(game);
	loading_screen(game);
	mlx_mouse_move(game->mlx->win, X_RES / 2, Y_RES / 2);
	mlx_loop_hook(game->mlx->mlx, main_game, game);
	mlx_hook(game->mlx->win, 2, 1L << 0, &keypress, game);
	mlx_hook(game->mlx->win, 3, 1L << 1, &keyrelease, game);
	mlx_hook(game->mlx->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx->mlx);
	exit_game(game);
	return (0);
}
