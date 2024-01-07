/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:14:36 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/07 16:24:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parse_filecontent(t_game *game)
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
		errmsg("Malloc error", false, game);
	game->fd = open(game->filename, O_RDONLY);
	read(game->fd, game->filecontent_str, game->filecontent_size);
	game->filecontent_str[game->filecontent_size] = '\0';
	close(game->fd);
	game->filecontent_tab = ft_split_nl(game->filecontent_str);
}

void	init_data(t_game **game, char **argv)
{
	*game = malloc(sizeof(t_game));
	if (!game)
		errmsg("Malloc error", false, *game);
	(*game)->filename = argv[1];
	parse_filecontent(*game);
}
