/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:46:58 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/20 17:54:55 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_rgb_value_cl(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (game->settings->cl_rgb[i] < 0 || game->settings->cl_rgb[i] > 255)
			errmsg("Valeur RGB invalide", true, game);
	}
}

static void	check_rgb_value_fl(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (game->settings->fl_rgb[i] < 0 || game->settings->fl_rgb[i] > 255)
			errmsg("Valeur RGB invalide", true, game);
	}
}

void	init_rgb(t_game *game)
{
	if (game->settings->fl_ispath == false)
	{
		game->settings->fl_rgb[0] = ft_atoi(game->settings->floor);
		game->settings->fl_rgb[1] = ft_atoi(ft_strchr(game->settings->floor,
					',') + 1);
		game->settings->fl_rgb[2] = ft_atoi(ft_strrchr(game->settings->floor,
					',') + 1);
		check_rgb_value_fl(game);
	}
	if (game->settings->cl_ispath == false)
	{
		game->settings->cl_rgb[0] = ft_atoi(game->settings->ceil);
		game->settings->cl_rgb[1] = ft_atoi(ft_strchr(game->settings->ceil,
					',') + 1);
		game->settings->cl_rgb[2] = ft_atoi(ft_strrchr(game->settings->ceil,
					',') + 1);
		check_rgb_value_cl(game);
	}
}
