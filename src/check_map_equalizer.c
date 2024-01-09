/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_equalizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:51:21 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/09 12:52:45 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static size_t	get_biggest_line(char **map)
{
	size_t	big;
	size_t	i;

	i = -1;
	big = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > big)
			big = ft_strlen(map[i]);
	}
	return (big);
}

static void	fill_line(char *line, size_t big)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(sizeof(char) * (big + 1));
	if (!tmp)
		errmsg("Malloc error", false, NULL);
	i = -1;
	while (line[++i])
		tmp[i] = line[i];
	while (i < big)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	free(line);
	line = ft_strdup(tmp);
	free(tmp);
}

void	map_equalizer(t_game *game)
{
	size_t	big;
	size_t	i;

	big = get_biggest_line(game->map);
	if (big < 3)
		errmsg("Map invalide", true, game);
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) < big)
			fill_line(game->map[i], big);
		i++;
	}
}
