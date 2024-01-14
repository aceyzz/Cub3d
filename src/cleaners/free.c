/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:38:20 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/14 10:27:20 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free_ptr(tab[i]);
	free_ptr(tab);
	tab = NULL;
}

void	free_data(t_game *game)
{
	free_ptr(game->filecontent_str);
	free_tab(game->file_tab);
	free_tab(game->map);
	free_tab(game->map_copy);
	free_ptr(game->settings->north);
	free_ptr(game->settings->south);
	free_ptr(game->settings->east);
	free_ptr(game->settings->west);
	free_ptr(game->settings->floor);
	free_ptr(game->settings->ceil);
	free_ptr(game->settings);
	free_ptr(game->player);
	free_ptr(game->ray);
	free_ptr(game);
}
