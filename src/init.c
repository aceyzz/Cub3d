/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:32:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/06 16:01:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* DEBUG */
void	print_data(t_game **game)
{
	int	i;

	i = -1;
	while ((*game)->filecontent[++i])
		printf("file line %d:\t%s\n", i, (*game)->filecontent[i]);
	printf("\n\nnord:\t%s\n", (*game)->north);
	printf("sud:\t%s\n", (*game)->south);
	printf("est:\t%s\n", (*game)->east);
	printf("west:\t%s\n", (*game)->west);
	printf("sol:\t%s\n", (*game)->floor);
	printf("ceil\t%s\n\n", (*game)->ceil);
	i = -1;
	while ((*game)->map[++i])
		printf("map line %d:\t%s|\n", i, (*game)->map[i]);
	i = -1;
	printf("\n");
	while ((*game)->map_copy[++i])
		printf("copy line %d:\t%s|\n", i, (*game)->map_copy[i]);
	printf("\n");
	i = -1;
	while (++i < 2)
		printf("rgb[%d]:\t%d|%d|%d\n", i, (*game)->rgb[i].r, (*game)->rgb[i].g, (*game)->rgb[i].b);
}

void	init_struct(t_game **game, char **argv)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		errmsg("Malloc error t_game", false, NULL);
	(*game)->filename = argv[1];
	get_filecontent(*game);
	get_params(*game);
	get_map(*game);
}
