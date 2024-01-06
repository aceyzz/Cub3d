/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:18:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 16:10:00 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_param(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0
		|| ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0
		|| ft_strncmp(str, "EA ", 3) == 0
		|| ft_strncmp(str, "F ", 2) == 0
		|| ft_strncmp(str, "C ", 2) == 0)
		return (true);
	else
		return (false);
}

static void	get_map_size(t_game *game)
{
	int		i;

	i = -1;
	game->mapsize = 0;
	while (game->filecontent[++i])
	{
		if (is_param(game->filecontent[i]) == false)
			game->mapsize++;
	}
}

static void	map_dup(t_game *game)
{
	int	i;

	game->map_copy = malloc(sizeof(char *) * (game->mapsize + 1));
	if (!game->map_copy)
		errmsg("Malloc error map_copy", true, game);
	i = -1;
	while (game->map[++i])
		game->map_copy[i] = ft_strdup(game->map[i]);
	game->map_copy[i] = NULL;
}

bool	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	get_map(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	get_map_size(game);
	game->map = malloc(sizeof(char *) * (game->mapsize + 1));
	if (!game->map)
		errmsg("Malloc error map", true, game);
	while (game->filecontent[i])
	{
		if (is_param(game->filecontent[i]) == false
			&& !is_empty_line(game->filecontent[i])
			&& ft_strlen(game->filecontent[i]) > 0
			&& game->filecontent[i][0] != '\n'
			&& game->filecontent[i][0] != '\0')
			game->map[k++] = ft_strdup(game->filecontent[i]);
		i++;
	}
	game->map[k] = NULL;
	normalize_map(game);
	map_dup(game);
}
