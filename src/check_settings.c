/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:04:27 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/08 19:46:47 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_nsew(t_game *game)
{
	if (ft_strncmp(game->settings->north + ft_strlen(game->settings->north) - 4,
			".xpm", 4) != 0
		|| ft_strncmp(game->settings->south + ft_strlen(game->settings->south)
			- 4, ".xpm", 4) != 0
		|| ft_strncmp(game->settings->east + ft_strlen(game->settings->east)
			- 4, ".xpm", 4) != 0
		|| ft_strncmp(game->settings->west + ft_strlen(game->settings->west)
			- 4, ".xpm", 4) != 0)
		errmsg("Textures doit etre en fichier .xpm", true, game);
	if (open(game->settings->north, O_RDONLY) == -1)
		errmsg("Texture North incorrecte", true, game);
	if (open(game->settings->south, O_RDONLY) == -1)
		errmsg("Texture South incorrecte", true, game);
	if (open(game->settings->east, O_RDONLY) == -1)
		errmsg("Texture East incorrecte", true, game);
	if (open(game->settings->west, O_RDONLY) == -1)
		errmsg("Texture West incorrecte", true, game);
}

static void	check_open(char *path, t_game *game)
{
	if (open(path, O_RDONLY) == -1)
		errmsg("Texture floor/ceiling not openable", true, game);
}

static void	check_rgb(char *rgb, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (rgb[++i])
	{
		if (rgb[i] == ',')
			j++;
	}
	if (j != 2)
		errmsg("RGB incorrect", true, game);
	i = -1;
	while (rgb[++i])
	{
		if (rgb[i] != ',' && !ft_isdigit(rgb[i]) && rgb[i] != ' ')
			errmsg("RGB incorrect", true, game);
	}
}

static void	check_fc(t_game *game)
{
	game->settings->fl_ispath = false;
	game->settings->cl_ispath = false;
	if (ft_strncmp(game->settings->floor + ft_strlen(game->settings->floor)
			- 4, ".xpm", 4) == 0)
		game->settings->fl_ispath = true;
	if (ft_strncmp(game->settings->ceil + ft_strlen(game->settings->ceil)
			- 4, ".xpm", 4) == 0)
		game->settings->cl_ispath = true;
	if (game->settings->fl_ispath == true)
		check_open(game->settings->floor, game);
	if (game->settings->cl_ispath == true)
		check_open(game->settings->ceil, game);
	if (game->settings->fl_ispath == false)
		check_rgb(game->settings->floor, game);
	if (game->settings->cl_ispath == false)
		check_rgb(game->settings->ceil, game);
	if (game->settings->fl_ispath == false)
		game->settings->floor = remove_spaces(game->settings->floor);
	if (game->settings->cl_ispath == false)
		game->settings->ceil = remove_spaces(game->settings->ceil);
	init_rgb(game);
}

void	check_settings(t_game *game)
{
	if (!game->settings->north || !game->settings->south
		|| !game->settings->east || !game->settings->west
		|| !game->settings->floor || !game->settings->ceil)
		errmsg("Missing settings", true, game);
	check_nsew(game);
	check_fc(game);
}
