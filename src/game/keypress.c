/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:31:01 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/15 11:08:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	keypress(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		exit_game(game);
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		move_player(keycode, game);
	if (keycode == K_LEFT || keycode == K_RIGHT)
		rotate_player(keycode, game);
	return (0);
}

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}
