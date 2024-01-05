/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:18:05 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 22:29:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free_ptr(tab[i]);
	free_ptr(tab);
}

void	free_params(t_game *game)
{
	free_ptr(game->north);
	free_ptr(game->south);
	free_ptr(game->east);
	free_ptr(game->west);
	free_ptr(game->floor);
	free_ptr(game->ceil);
}

void	free_data(t_game *game)
{
	free_tab(game->filecontent);
	free_tab(game->map);
	free_tab(game->map_copy);
	free_params(game);
	if (game)
		free_ptr(game);
}
