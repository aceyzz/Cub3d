/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:26:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/14 10:19:17 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ')
		return (false);
	return (true);
}

static void	check_valid_chars(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_valid_char(game->map[i][j]) == false)
				errmsg("Caractère invalide dans la map", true, game);
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				count++;
			j++;
		}
	}
	if (count != 1)
		errmsg("Nombre de joueurs invalide", true, game);
}

void	check_map(t_game *game)
{
	check_valid_chars(game);
	map_equalizer(game);
	create_map_copy(&game);
	check_map_border(game);
}
