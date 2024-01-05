/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:13:20 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 20:56:06 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	errmsg(const char *errmsg, bool to_free, t_game *game)
{
	write(2, "Error:\n", 8);
	printf(YEL);
	printf("%s.\n", errmsg);
	printf(RST);
	if (to_free == true)
		free_data(game);
	exit(1);
}

void	exit_game(t_game *game)
{
	printf(CYA);
	printf("Goodbye !\n");
	printf(RST);
	free_data(game);
	exit(0);
}
