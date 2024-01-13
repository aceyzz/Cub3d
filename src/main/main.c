/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:28:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/13 13:26:30 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	init_data(&game, argv);
	print_data(game);
	exit_game(game);
	return (0);
}

/*

	launch the game after print_data (debug)

*/