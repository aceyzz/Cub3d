/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:01:20 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 22:36:22 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	init_struct(&game, argv);
	print_data(&game);
	exit_game(game);
	return (0);
}

/*

parse fichier + map + params est OK
On doit maintenant s'occuper du check des params
puis check de la map (charac, au moins 1 player, pas de trou, etc)

*/