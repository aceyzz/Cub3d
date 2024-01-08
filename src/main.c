/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:28:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/08 17:22:59 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_data(t_game *game)
{
	int	i;

	i = -1;
	printf("filename = \033[1;32m%s" RST, game->filename);
	printf("\n ---------------------- \n");
	printf("filecontent_str =\n\033[1;32m%s" RST, game->filecontent_str);
	printf("\n ---------------------- \n");
	printf("file_tab =\n");
	while (game->file_tab[++i])
		printf("ligne %d:\t\033[1;32m%s|\n" RST, i, game->file_tab[i]);
	printf("\n ---------------------- \n");
	printf("filecontent_size = \033[1;32m%zu" RST, game->filecontent_size);
	printf("\n ---------------------- \n");
	printf("settings->north = \033[1;32m%s\n" RST, game->settings->north);
	printf("settings->south = \033[1;32m%s\n" RST, game->settings->south);
	printf("settings->east = \033[1;32m%s\n" RST, game->settings->east);
	printf("settings->west = \033[1;32m%s\n" RST, game->settings->west);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	check_args(argc, argv);
	init_data(&game, argv);
	// check_data(&game);
	// launch_game(&game);
	print_data(game);
	free_data(game);
	return (0);
}
