/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:08:10 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 10:05:18 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_params(t_game *game)
{
	int	i;

	i = -1;
	while (game->filecontent[++i])
	{
		if (ft_strncmp(game->filecontent[i], "NO ", 3) == 0)
			game->north = ft_strdup(game->filecontent[i] + 3);
		else if (ft_strncmp(game->filecontent[i], "SO ", 3) == 0)
			game->south = ft_strdup(game->filecontent[i] + 3);
		else if (ft_strncmp(game->filecontent[i], "WE ", 3) == 0)
			game->west = ft_strdup(game->filecontent[i] + 3);
		else if (ft_strncmp(game->filecontent[i], "EA ", 3) == 0)
			game->east = ft_strdup(game->filecontent[i] + 3);
		else if (ft_strncmp(game->filecontent[i], "F ", 2) == 0)
			game->floor = ft_strdup(game->filecontent[i] + 2);
		else if (ft_strncmp(game->filecontent[i], "C ", 2) == 0)
			game->ceil = ft_strdup(game->filecontent[i] + 2);
	}
}
