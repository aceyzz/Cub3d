/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:31:17 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 10:03:16 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_rgb(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == false && str[i] != ',')
			return (false);
	}
	return (true);
}

static void	trim_floor(t_game *game)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = game->floor;
	game->floor = malloc(sizeof(char) * (strlen(tmp) + 1));
	i = -1;
	j = 0;
	while (tmp[++i])
	{
		if (tmp[i] != ' ')
			game->floor[j++] = tmp[i];
	}
	game->floor[j] = '\0';
	free(tmp);
}

void	trim_fc(t_game *game)
{
	char	*tmp;
	int		i;
	int		j;

	trim_floor(game);
	tmp = game->ceil;
	game->ceil = malloc(sizeof(char) * (strlen(tmp) + 1));
	i = -1;
	j = 0;
	while (tmp[++i])
	{
		if (tmp[i] != ' ')
			game->ceil[j++] = tmp[i];
	}
	game->ceil[j] = '\0';
	free(tmp);
}
