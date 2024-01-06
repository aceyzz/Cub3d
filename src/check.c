/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:43:47 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 10:10:46 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_data(t_game *game)
{
	if (!game->north || !game->north[0] || !game->south || !game->south[0]
		|| !game->east || !game->east[0] || !game->west || !game->west[0]
		|| !game->floor || !game->floor[0] || !game->ceil || !game->ceil[0])
		errmsg("Parametres manquants", true, game);
	check_nsew(game);
	check_fc(game);
	if ((game->rgb[0].is_path == false && game->rgb[0].is_rgb == false))
		errmsg("Réglages FLOOR incorrects", true, game);
	if ((game->rgb[1].is_path == false && game->rgb[1].is_rgb == false))
		errmsg("Réglages CEIL incorrects", true, game);
}
