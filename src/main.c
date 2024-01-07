/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:28:40 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/07 16:25:47 by cedmulle         ###   ########.fr       */
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
	printf("filecontent_tab =\n");
	while (game->filecontent_tab[++i])
		printf("ligne %d:\t\033[1;32m%s|\n" RST, i, game->filecontent_tab[i]);
	printf("\n ---------------------- \n");
	printf("filecontent_size = \033[1;32m%zu" RST, game->filecontent_size);
	printf("\n ---------------------- \n");
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
