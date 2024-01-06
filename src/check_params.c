/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:04:39 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 10:06:31 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		errmsg("Nombre d'argument invalide", false, NULL);
	if (!argv[1])
		errmsg("Argument invalide", false, NULL);
	if (ft_strlen(argv[1]) < 5)
		errmsg("Fichier invalide", false, NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		errmsg("Extension du fichier invalide", false, NULL);
	if (open(argv[1], O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier", false, NULL);
}

void	check_nsew(t_game *game)
{
	if (open(game->north, O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier NORTH", true, game);
	if (open(game->south, O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier SOUTH", true, game);
	if (open(game->east, O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier EAST", true, game);
	if (open(game->west, O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier WEST", true, game);
}

static void	check_openable(t_game *game)
{
	int	fd;

	if (game->rgb[0].is_path == true)
	{
		fd = open(game->floor, O_RDONLY);
		if (fd == -1)
			errmsg("Impossible d'ouvrir le fichier FLOOR", true, game);
		close(fd);
	}
	if (game->rgb[1].is_path == true)
	{
		fd = open(game->ceil, O_RDONLY);
		if (fd == -1)
			errmsg("Impossible d'ouvrir le fichier CEIL", true, game);
		close(fd);
	}
}

void	check_rgb_values(t_game *game)
{
	if (game->rgb[0].is_rgb == true)
	{
		if (game->rgb[0].r < 0 || game->rgb[0].r > 255)
			errmsg("Valeur R du FLOOR incorrecte", true, game);
		if (game->rgb[0].g < 0 || game->rgb[0].g > 255)
			errmsg("Valeur G du FLOOR incorrecte", true, game);
		if (game->rgb[0].b < 0 || game->rgb[0].b > 255)
			errmsg("Valeur B du FLOOR incorrecte", true, game);
	}
	if (game->rgb[1].is_rgb == true)
	{
		if (game->rgb[1].r < 0 || game->rgb[1].r > 255)
			errmsg("Valeur R du CEIL incorrecte", true, game);
		if (game->rgb[1].g < 0 || game->rgb[1].g > 255)
			errmsg("Valeur G du CEIL incorrecte", true, game);
		if (game->rgb[1].b < 0 || game->rgb[1].b > 255)
			errmsg("Valeur B du CEIL incorrecte", true, game);
	}
}

void	check_fc(t_game *game)
{
	trim_fc(game);
	game->rgb[0].is_rgb = false;
	game->rgb[1].is_rgb = false;
	if (is_valid_rgb(game->floor))
	{
		game->rgb[0].is_rgb = true;
		game->rgb[0].is_path = false;
		game->rgb[0].r = ft_atoi(game->floor);
		game->rgb[0].g = ft_atoi(ft_strchr(game->floor, ',') + 1);
		game->rgb[0].b = ft_atoi(ft_strrchr(game->floor, ',') + 1);
	}
	else
		game->rgb[0].is_path = true;
	if (is_valid_rgb(game->ceil))
	{
		game->rgb[1].is_rgb = true;
		game->rgb[1].is_path = false;
		game->rgb[1].r = ft_atoi(game->ceil);
		game->rgb[1].g = ft_atoi(ft_strchr(game->ceil, ',') + 1);
		game->rgb[1].b = ft_atoi(ft_strrchr(game->ceil, ',') + 1);
	}
	else
		game->rgb[1].is_path = true;
	check_rgb_values(game);
	check_openable(game);
}
