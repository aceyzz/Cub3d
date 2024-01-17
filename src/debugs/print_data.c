/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:13:39 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/17 19:50:29 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	print_fileinfos(t_game *game)
{
	int	i;

	i = -1;
	printf("filename = \033[1;32m%s" RST, game->filename);
	printf("\n ---------------------- \n");
	printf("filecontent_str =\n\033[1;34m%s" RST, game->filecontent_str);
	printf("\n ---------------------- \n");
	printf("file_tab =\n");
	while (game->file_tab[++i])
		printf("ligne %d:\t\033[1;33m%s|\n" RST, i, game->file_tab[i]);
	printf(" ---------------------- \n");
	printf("\n\033[1;31mPRINT MAPS:\n" RST);
	i = -1;
	printf("map =\n");
	while (game->map[++i])
		printf("ligne %d:\t\033[1;32m%s|\n" RST, i, game->map[i]);
	printf(" ---------------------- \n");
	i = -1;
	printf("map_copy =\n");
	while (game->map_copy[++i])
		printf("ligne %d:\t\033[1;33m%s|\n" RST, i, game->map_copy[i]);
	printf(" ---------------------- \n");
	printf("map_x = \033[1;35m%zu\n" RST, game->map_x);
	printf("map_y = \033[1;35m%zu\n" RST, game->map_y);
	printf(" ---------------------- \n");
}

static void	print_settings_player(t_game *game)
{
	int	i;

	i = -1;
	printf("\n\033[1;31mPRINT SETTINGS:\n" RST);
	printf("settings->north = \033[1;36m%s\n" RST, game->settings->north);
	printf("settings->south = \033[1;36m%s\n" RST, game->settings->south);
	printf("settings->east = \033[1;36m%s\n" RST, game->settings->east);
	printf("settings->west = \033[1;36m%s\n" RST, game->settings->west);
	printf("settings->floor = \033[1;36m%s\n" RST, game->settings->floor);
	printf("settings->ceil = \033[1;36m%s\n" RST, game->settings->ceil);
	printf(" ---------------------- \n");
	i = -1;
	while (++i < 3)
	{
		printf("settings->fl_rgb[%d] = \033[1;31m%d\033[0;m ", i,
			game->settings->fl_rgb[i]);
		printf("\tsettings->cl_rgb[%d] = \033[1;34m%d\033[0;m\n", i,
			game->settings->cl_rgb[i]);
	}
	printf(" ---------------------- \n\n\033[1;31mPRINT PLAYER:\n" RST);
	printf("player->pos_x = \033[1;36m%f\n" RST, game->player->pos_x);
	printf("player->pos_y = \033[1;36m%f\n" RST, game->player->pos_y);
	printf("player->dir_x = \033[1;35m%f\n" RST, game->player->dir_x);
	printf("player->dir_y = \033[1;35m%f\n" RST, game->player->dir_y);
}

static void	print_rays(t_game *game)
{
	printf("\n\033[1;31mPRINT RAYS:\n" RST);
	printf("ray->pos_x = \033[1;36m%f\n" RST, game->ray->pos_x);
	printf("ray->pos_y = \033[1;36m%f\n" RST, game->ray->pos_y);
	printf("ray->dir_x = \033[1;36m%f\n" RST, game->ray->dir_x);
	printf("ray->dir_y = \033[1;36m%f\n" RST, game->ray->dir_y);
}

void	print_data(t_game *game)
{
	printf("\n\033[1;31mPRINT FILE INFO:\n" RST);
	print_fileinfos(game);
	print_settings_player(game);
	print_rays(game);
	printf(" --------------- \n\n");
}
