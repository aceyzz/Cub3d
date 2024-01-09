/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:04:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/09 19:58:50 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_first_last_line(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[0][++i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != ' ')
			errmsg("Bordure haute de la map invalide", true, game);
		i++;
	}
	i = -1;
	while (game->map[tab_size(game->map) - 1][++i])
	{
		if (game->map[tab_size(game->map) - 1][i] != '1'
			&& game->map[tab_size(game->map) - 1][i] != ' ')
			errmsg("Bordure basse de la map invalide", true, game);
	}
}

static void	check_left_right_border(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (game->map[i][0] != '1' && game->map[i][0] != ' ')
			errmsg("Bordure gauche de la map invalide", true, game);
		if (game->map[i][ft_strlen(game->map[i]) - 1] != '1'
			&& game->map[i][ft_strlen(game->map[i]) - 1] != ' ')
			errmsg("Bordure droite de la map invalide", true, game);
	}
}

void	check_borders(t_game *game)
{
	check_first_last_line(game);
	check_left_right_border(game);
}
