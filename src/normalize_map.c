/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:12:49 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 15:59:17 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	find_biggest_line(t_game *game)
{
	size_t	biggest;
	int		i;

	i = 0;
	biggest = ft_strlen(game->map[i++]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) > biggest)
			biggest = ft_strlen(game->map[i]);
		i++;
	}
	return (biggest);
}

static void	normalize_line(t_game *game, size_t i, size_t len)
{
	char	*tmp;
	size_t	j;

	j = 0;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		errmsg("Malloc error tmp", true, game);
	while (j < len)
	{
		if (j < ft_strlen(game->map[i]))
			tmp[j] = game->map[i][j];
		else
			tmp[j] = ' ';
		j++;
	}
	tmp[j] = '\0';
	free(game->map[i]);
	game->map[i] = tmp;
}

void	normalize_map(t_game *game)
{
	size_t	biggest;
	int		i;

	i = 0;
	biggest = find_biggest_line(game);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) < biggest)
			normalize_line(game, i, biggest);
		i++;
	}
}
