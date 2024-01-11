/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:08:57 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/11 15:32:45 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	create_map(t_game **game, int start, int end)
{
	int	i;

	i = 0;
	(*game)->map = malloc(sizeof(char *) * (end - start + 2));
	if (!(*game)->map)
		errmsg("Malloc error", true, (*game));
	(*game)->map[end - start + 1] = NULL;
	while (start <= end)
	{
		(*game)->map[i] = ft_strdup((*game)->file_tab[start]);
		if (!(*game)->map[i])
			errmsg("Malloc error", true, (*game));
		start++;
		i++;
	}
}

void	parse_map(t_game *game)
{
	int	i;
	int	end;

	i = 0;
	while (game->file_tab[i + 1])
		i++;
	while (is_empty_line(game->file_tab[i]))
		i--;
	end = i;
	while (i > 0 && !is_empty_line(game->file_tab[i])
		&& ft_strncmp(game->file_tab[i], "NO ", 3)
		&& ft_strncmp(game->file_tab[i], "SO ", 3)
		&& ft_strncmp(game->file_tab[i], "EA ", 3)
		&& ft_strncmp(game->file_tab[i], "WE ", 3)
		&& ft_strncmp(game->file_tab[i], "F ", 2)
		&& ft_strncmp(game->file_tab[i], "C ", 2))
		i--;
	if (i == 0 || (end - i) < 3)
		errmsg("Taille de map invalide", true, game);
	create_map(&game, ++i, end);
	if (tab_size(game->map) + 6 != tab_size(game->file_tab))
		errmsg("Map invalide detectée", true, game);
	check_map(game);
}
