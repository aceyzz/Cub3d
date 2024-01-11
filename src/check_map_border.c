/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/11 17:11:40 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_top_bottom(t_game *game)
{
	int	i;
	int	last;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != ' ')
			errmsg("Bordure haute de la map incorrecte", true, game);
		i++;
	}
	last = 0;
	while (game->map[last + 1])
		last++;
	i = 0;
	while (game->map[last][i])
	{
		if (game->map[last][i] != '1' && game->map[last][i] != ' ')
			errmsg("Bordure basse de la map inccorecte", true, game);
		i++;
	}
}

static void	check_left_right(t_game *game)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k] && game->map[i][k] == ' ')
			k++;
		if (game->map[i][k] != '1')
			errmsg("Bordure gauche de la map incorrecte", true, game);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k + 1])
			k++;
		while (game->map[i][k] && game->map[i][k] == ' ')
			k--;
		if (game->map[i][k] != '1')
			errmsg("Bordure droite de la map incorrecte", true, game);
		i++;
	}
}

void	check_map_border(t_game *game)
{
	check_top_bottom(game);
	check_left_right(game);
}
