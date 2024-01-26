/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:31:01 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/26 14:15:56 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	debug_printer(t_game *game)
{
	printf("pos_x: \033[1;31m%f\033[0m -- ", game->player->pos_x);
	printf("pos_y: \033[1;34m%f\033[0m -- ", game->player->pos_y);
	printf("dir_x: \033[1;32m%f\033[0m -- ", game->player->dir_x);
	printf("dir_y: \033[1;33m%f\033[0m --\n", game->player->dir_y);
}

int	keyrelease(int keycode, t_game *game)
{
	if (keycode == K_W)
		game->keys->w = false;
	if (keycode == K_A)
		game->keys->a = false;
	if (keycode == K_S)
		game->keys->s = false;
	if (keycode == K_D)
		game->keys->d = false;
	if (keycode == K_LEFT)
		game->keys->left = false;
	if (keycode == K_RIGHT)
		game->keys->right = false;
	if (keycode == K_LSHIFT)
		game->keys->shift = false;
	if (keycode == K_R)
		game->keys->r = false;
	if (keycode == K_E)
	{
		game->keys->e = false;
		game->keys->no_auto = true;
	}
	return (0);
}

static void	start_menu(int keycode, t_game *game)
{
	if (keycode == K_ENTER)
	{
		mlx_clear_window(game->mlx->mlx, game->mlx->win);
		game->keys->enter = true;
	}
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		exit_game(game);
	if (keycode == K_W)
		game->keys->w = true;
	if (keycode == K_A)
		game->keys->a = true;
	if (keycode == K_S)
		game->keys->s = true;
	if (keycode == K_D)
		game->keys->d = true;
	if (keycode == K_LEFT)
		game->keys->left = true;
	if (keycode == K_RIGHT)
		game->keys->right = true;
	if (keycode == K_LSHIFT)
		game->keys->shift = true;
	if (keycode == K_R)
		game->keys->r = true;
	if (keycode == K_E)
		game->keys->e = true;
	start_menu(keycode, game);
	if (DEBUG == 1)
		debug_printer(game);
	return (0);
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}
