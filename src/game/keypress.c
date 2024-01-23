/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:31:01 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 07:30:06 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	debug_printer(t_game *game)
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
	return (0);
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
	return (0);
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}
