/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:00:00 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/28 11:50:05 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	handle_ammos(t_game *game)
{
	int	i;

	i = 0;
	while (++i <= game->gun->ammo)
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->gun->f_ammo, X_RES - 225 + (i * 22), Y_RES
			- game->gun->e_size_y - 35);
	while (i <= 7)
	{
		mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
			game->gun->e_ammo, X_RES - 225 + (i * 22), Y_RES
			- game->gun->e_size_y - 35);
		i++;
	}
}

void	health_minigun(t_game *game)
{
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->health->img, X_RES / 2 - (game->health->width / 2), 3);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->minigun->img, X_RES / 2 + 185, 5);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->skin->img, X_RES / 2 - 220, 5);
}
