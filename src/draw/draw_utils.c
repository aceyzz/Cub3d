/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:29:49 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/28 22:01:45 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	add_shader(int color, double distance)
{
	int	rgb[3];

	rgb[0] = (color & 0xFF0000) >> 16;
	rgb[1] = (color & 0xFF00) >> 8;
	rgb[2] = (color & 0xFF);
	rgb[0] = rgb[0] - (rgb[0] * distance);
	rgb[1] = rgb[1] - (rgb[1] * distance);
	rgb[2] = rgb[2] - (rgb[2] * distance);
	return (rgb_to_mlx(rgb));
}

int	rgb_to_mlx(int rgb[3])
{
	return (((rgb[0] & 0xFF) << 16) + ((rgb[1] & 0xFF) << 8) + (rgb[2] & 0xFF));
}

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mlx->addr + (y * game->mlx->len + x * (game->mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

int	apply_fog(unsigned int color, double fog_factor)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = r * fog_factor;
	g = g * fog_factor;
	b = b * fog_factor;
	color = (r << 16) | (g << 8) | b;
	return (color);
}
