/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:09:29 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/27 19:25:50 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	gunshot(void)
{
	if (fork() == 0)
		execl("/usr/bin/afplay", "afplay", "./sound/gunshot.mp3", NULL);
}

void	dryshot(void)
{
	if (fork() == 0)
		execl("/usr/bin/afplay", "afplay", "./sound/dryshot.mp3", NULL);
}

void	reload(void)
{
	if (fork() == 0)
		execl("/usr/bin/afplay", "afplay", "./sound/reload.mp3", NULL);
}
