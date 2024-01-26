/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:14:36 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/26 12:44:45 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	parse_filecontent(t_game *game)
{
	char	buf[1];

	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
		errmsg("Impossible d'ouvrir le fichier", false, game);
	while (read(game->fd, buf, 1))
		game->filecontent_size++;
	close(game->fd);
	game->filecontent_str = malloc(sizeof(char) * (game->filecontent_size + 1));
	if (!game->filecontent_str)
		errmsg("Malloc error", true, game);
	game->fd = open(game->filename, O_RDONLY);
	read(game->fd, game->filecontent_str, game->filecontent_size);
	game->filecontent_str[game->filecontent_size] = '\0';
	close(game->fd);
	if (!game->filecontent_str || !game->filecontent_str[0])
		errmsg("Fichier vide", true, game);
	game->file_tab = ft_split_nl(game->filecontent_str);
	if (!game->file_tab || !game->file_tab[0])
		errmsg("Malloc error file_tab", true, game);
	if (tab_size(game->file_tab) < 9)
		errmsg("Fichier trop petit", true, game);
}

static void	parse_settings(t_game **game)
{
	int	i;

	i = -1;
	while ((*game)->file_tab[++i])
	{
		if (ft_strncmp((*game)->file_tab[i], "NO ", 3) == 0)
			(*game)->settings->north = ft_strdup((*game)->file_tab[i] + 3);
		else if (ft_strncmp((*game)->file_tab[i], "SO ", 3) == 0)
			(*game)->settings->south = ft_strdup((*game)->file_tab[i] + 3);
		else if (ft_strncmp((*game)->file_tab[i], "EA ", 3) == 0)
			(*game)->settings->east = ft_strdup((*game)->file_tab[i] + 3);
		else if (ft_strncmp((*game)->file_tab[i], "WE ", 3) == 0)
			(*game)->settings->west = ft_strdup((*game)->file_tab[i] + 3);
		else if (ft_strncmp((*game)->file_tab[i], "F ", 2) == 0)
			(*game)->settings->floor = ft_strdup((*game)->file_tab[i] + 2);
		else if (ft_strncmp((*game)->file_tab[i], "C ", 2) == 0)
			(*game)->settings->ceil = ft_strdup((*game)->file_tab[i] + 2);
	}
	check_settings(*game);
}

static void	init_keys(t_game *game)
{
	game->keys = malloc(sizeof(t_keys));
	if (!game->keys)
		errmsg("Malloc error", true, game);
	game->keys->w = false;
	game->keys->a = false;
	game->keys->s = false;
	game->keys->d = false;
	game->keys->left = false;
	game->keys->right = false;
	game->keys->shift = false;
	game->keys->r = false;
	game->keys->e = true;
	game->keys->enter = false;
}

void	init_data(t_game **game, char **argv)
{
	*game = malloc(sizeof(t_game));
	if (!game || !*game)
		errmsg("Malloc error", false, *game);
	(*game)->settings = malloc(sizeof(t_settings));
	if (!(*game)->settings)
		errmsg("Malloc error", true, *game);
	(*game)->filename = argv[1];
	parse_filecontent(*game);
	parse_settings(game);
	parse_map(*game);
	init_player(game);
	init_keys(*game);
	if (!(*game)->settings->fl_ispath || !(*game)->settings->cl_ispath)
	{
		(*game)->player->move_speed *= 0.45;
		(*game)->player->rota_speed *= 0.45;
	}
	(*game)->frame = 0;
}
