/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:11:50 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/21 18:23:39 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_player_ns(t_game *game, int i, int k)
{
	if (game->map[i][k] == 'N')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if (game->map[i][k] == 'S')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
}

static void	init_player_ew(t_game *game, int i, int k)
{
	if (game->map[i][k] == 'E')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
	else if (game->map[i][k] == 'W')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
	}
}

static void	init_player_info(t_game *game)
{
	int	i;
	int	k;

	i = -1;
	while (game->map[++i])
	{
		k = -1;
		while (game->map[i][++k])
		{
			if (game->map[i][k] == 'N' || game->map[i][k] == 'S'
				|| game->map[i][k] == 'E' || game->map[i][k] == 'W')
			{
				game->player->pos_x = k + 0.5;
				game->player->pos_y = i + 0.5;
				init_player_ns(game, i, k);
				init_player_ew(game, i, k);
				return ;
			}
		}
	}
	errmsg("Position du joueur non trouvée", true, game);
}

void	init_player(t_game **game)
{
	(*game)->player = malloc(sizeof(t_player));
	if (!(*game)->player)
		errmsg("Malloc error", true, *game);
	init_player_info(*game);
}
