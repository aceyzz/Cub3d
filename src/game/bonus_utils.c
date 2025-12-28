/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:00:00 by cedmulle          #+#    #+#             */
/*   Updated: 2025/12/28 16:15:12 by cedmulle         ###   ########.fr       */
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

void	mute_music(t_game *game)
{
	static int	i = 0;
	int			ret;

	if (game->keys->m == true)
	{
		ret = system("killall afplay");
		(void)ret;
		i = 1;
	}
	if (game->keys->m == false && i == 1)
	{
		sound_effect(SOUNDTRACK);
		i = 0;
	}
}
