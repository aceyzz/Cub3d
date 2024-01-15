/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rota.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:39:16 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/15 11:06:07 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(int keycode, t_game *game)
{
	if (keycode == K_LEFT)
	{
		game->player->orientation += ROTA_SPEED;
		if (game->player->orientation > 2 * M_PI)
			game->player->orientation -= 2 * M_PI;
	}
	if (keycode == K_RIGHT)
	{
		game->player->orientation -= ROTA_SPEED;
		if (game->player->orientation < 0)
			game->player->orientation += 2 * M_PI;
	}
}
