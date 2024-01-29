/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:31:01 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/29 15:05:56 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

static void	keypress_next(int keycode, t_game *game)
{
	if (keycode == K_ENTER && game->keys->enter == false)
	{
		mlx_clear_window(game->mlx->mlx, game->mlx->win);
		game->keys->enter = true;
	}
	if (keycode == K_M)
	{
		game->keys->m = !game->keys->m;
		mute_music(game);
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
	if (keycode == K_P)
		game->keys->p = !game->keys->p;
	keypress_next(keycode, game);
	return (0);
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}
