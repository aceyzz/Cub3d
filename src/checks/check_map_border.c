/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/12 10:32:18 by cedmulle         ###   ########.fr       */
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
	last = size_tab(game->map) - 1;
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

	i = -1;
	while (game->map[++i])
	{
		k = 0;
		while (game->map[i][k] && game->map[i][k] == ' ')
			k++;
		if (game->map[i][k] != '1')
			errmsg("Bordure gauche de la map incorrecte", true, game);
	}
	i = -1;
	while (game->map[++i])
	{
		k = 0;
		while (game->map[i][k + 1])
			k++;
		while (game->map[i][k] && game->map[i][k] == ' ')
			k--;
		if (game->map[i][k] != '1')
			errmsg("Bordure droite de la map incorrecte", true, game);
	}
}

static size_t	moturki(t_game *game, size_t y, size_t x)
{
	if (y == 0 || x == 0 || y == size_tab(game->map) - 1
		|| x == ft_strlen(game->map[y]) - 1)
		return (0);
	if (game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' '
		|| game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' ')
		return (0);
	return (1);
}

static void	check_linked_borders(t_game *game)
{
	size_t	i;
	size_t	k;

	i = -1;
	while (game->map[++i])
	{
		k = -1;
		while (game->map[i][++k])
		{
			if (game->map[i][k] == '0'
				|| game->map[i][k] == 'N' || game->map[i][k] == 'S'
				|| game->map[i][k] == 'E' || game->map[i][k] == 'W')
				if (moturki(game, i, k) == 0)
					errmsg("Map non correctement fermée", true, game);
		}
	}
}

void	check_map_border(t_game *game)
{
	check_top_bottom(game);
	check_left_right(game);
	check_linked_borders(game);
}
