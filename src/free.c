/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:38:20 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/08 20:08:06 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void	free_data(t_game *game)
{
	free_ptr(game->filecontent_str);
	free_tab(game->file_tab);
	free_ptr(game->settings->north);
	free_ptr(game->settings->south);
	free_ptr(game->settings->east);
	free_ptr(game->settings->west);
	free_ptr(game->settings->floor);
	free_ptr(game->settings->ceil);
	free_ptr(game->settings);
	free_ptr(game);
}
