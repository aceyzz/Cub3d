/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:11:50 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/14 10:38:19 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_player_position(t_game *game, int i, int k)
{
	game->player->pos_x = k + 0.5;
	game->player->pos_y = i + 0.5;
}

static void	init_player_orientation(t_game *game, int i, int k)
{
	if (game->map[i][k] == 'N')
		game->player->orientation = 3 * M_PI / 2;
	else if (game->map[i][k] == 'S')
		game->player->orientation = M_PI / 2;
	else if (game->map[i][k] == 'E')
		game->player->orientation = 0;
	else if (game->map[i][k] == 'W')
		game->player->orientation = M_PI;
	else
		errmsg("Orientation du joueur non trouvée", true, game);
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
				init_player_position(game, i, k);
				init_player_orientation(game, i, k);
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
