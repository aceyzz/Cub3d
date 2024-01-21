/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:09:43 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/21 13:23:49 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main_game(t_game *game)
{
	draw_floor_ceiling(game);
	draw_hud(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0,
		0);
	return (0);
}
