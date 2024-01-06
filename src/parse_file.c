/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:20:12 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 09:08:22 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_filesize(t_game *game)
{
	int		fd;
	int		ret;
	char	buf[1];

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		errmsg("Impossible d'ouvrir le fichier", true, game);
	ret = read(fd, buf, 1);
	while (ret > 0)
	{
		game->filesize++;
		ret = read(fd, buf, 1);
	}
	close(fd);
}

void	get_filecontent(t_game *game)
{
	char	*buffer;
	int		fd;
	int		ret;

	get_filesize(game);
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		errmsg("Impossible d'ouvrir le fichier", true, game);
	buffer = malloc(sizeof(char) * (game->filesize + 1));
	if (!buffer)
		errmsg("Malloc error filecontent_str", true, game);
	ret = read(fd, buffer, game->filesize);
	if (ret == -1)
		errmsg("Error reading file", true, game);
	buffer[game->filesize] = '\0';
	game->filecontent = ft_split(buffer, '\n');
	free_ptr(buffer);
	close(fd);
}
