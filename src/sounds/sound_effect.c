/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:09:29 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/27 19:55:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sound_effect(int effect)
{
	if (effect == GUNSHOT)
		if (fork() == 0)
			execl("/usr/bin/afplay", "afplay", "./sound/gunshot.mp3", NULL);
	if (effect == DRYSHOT)
		if (fork() == 0)
			execl("/usr/bin/afplay", "afplay", "./sound/dryshot.mp3", NULL);
	if (effect == RELOAD)
		if (fork() == 0)
			execl("/usr/bin/afplay", "afplay", "./sound/reload.mp3", NULL);
	if (effect == SOUNDTRACK)
		if (fork() == 0)
			execl("/usr/bin/afplay", "afplay", "./sound/soundtrack.mp3", NULL);
}
