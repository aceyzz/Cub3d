/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:37:41 by cedmulle          #+#    #+#             */
/*   Updated: 2025/12/28 16:14:42 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	errmsg(const char *errmsg, bool to_free, t_game *game)
{
	int	ret;
	ret = write(2, "\033[1;31mError:\n", 14);
	(void)ret;
	printf(YEL);
	printf("%s.\n", errmsg);
	printf(RST);
	if (to_free == true)
		free_data(game);
	exit(1);
}

void	exit_game(t_game *game)
{
	int	ret;
	
	ret = system("killall afplay");
	(void)ret;
	printf(CYA);
	printf("Goodbye !\n");
	printf(RST);
	free_data(game);
	exit(0);
}
