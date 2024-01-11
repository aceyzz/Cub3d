/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:28:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/11 15:33:09 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_data(t_game *game)
{
	int	i;

	i = -1;
	printf("\nfilename = \033[1;32m%s" RST, game->filename);
	printf("\n ---------------------- \n");
	printf("filecontent_str =\n\033[1;34m%s" RST, game->filecontent_str);
	printf("\n ---------------------- \n");
	printf("file_tab =\n");
	while (game->file_tab[++i])
		printf("ligne %d:\t\033[1;33m%s|\n" RST, i, game->file_tab[i]);
	printf(" ---------------------- \n");
	printf("settings->north = \033[1;36m%s\n" RST, game->settings->north);
	printf("settings->south = \033[1;36m%s\n" RST, game->settings->south);
	printf("settings->east = \033[1;36m%s\n" RST, game->settings->east);
	printf("settings->west = \033[1;36m%s\n" RST, game->settings->west);
	printf("settings->floor = \033[1;36m%s\n" RST, game->settings->floor);
	printf("settings->ceil = \033[1;36m%s\n" RST, game->settings->ceil);
	printf(" ---------------------- \n");
	i = -1;
	while (++i < 3)
		printf("settings->fl_rgb[%d] = \033[1;31m%d\033[0;m  \t| settings->cl_rgb[%d] = \033[1;34m%d\033[0;m\n", i,
			game->settings->fl_rgb[i], i, game->settings->cl_rgb[i]);
	printf(" ---------------------- \n");
	i = -1;
	printf("map =\n");
	while (game->map[++i])
		printf("ligne %d:\t\033[1;32m%s|\n" RST, i, game->map[i]);
	printf(" ---------------------- \n");
	// i = -1;
	// printf("map_copy =\n");
	// while (game->map_copy[++i])
	// 	printf("ligne %d:\t\033[1;33m%s|\n" RST, i, game->map_copy[i]);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	init_data(&game, argv);
	// launch_game(&game);
	print_data(game);
	exit_game(game);
	return (0);
}
