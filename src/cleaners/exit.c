/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:37:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/28 10:06:28 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	errmsg(const char *errmsg, bool to_free, t_game *game)
{
	write(2, "\033[1;31mError:\n", 14);
	printf(YEL);
	printf("%s.\n", errmsg);
	printf(RST);
	if (to_free == true)
		free_data(game);
	exit(1);
}

void	exit_game(t_game *game)
{
	system("killall afplay");
	printf(CYA);
	printf("Goodbye !\n");
	printf(RST);
	free_data(game);
	exit(0);
}
