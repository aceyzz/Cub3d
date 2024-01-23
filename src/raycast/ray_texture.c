/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:42:02 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/23 09:51:12 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_textures(t_texture *texture, char *addr, int len, int bpp)
{
	texture->addr = addr;
	texture->len = len;
	texture->bpp = bpp;
}

int	get_texture_color_fc(t_game *game, char fc, int tex_x, int tex_y)
{
	t_texture	texture;
	int			index;

	if (fc == 'F')
		set_textures(&texture, game->floor->addr, game->floor->len,
			game->floor->bpp);
	else if (fc == 'C')
		set_textures(&texture, game->ceil->addr, game->ceil->len,
			game->ceil->bpp);
	else
		return (0);
	tex_x = fmax(0, fmin(tex_x, TEX_SIZE - 1));
	tex_y = fmax(0, fmin(tex_y, TEX_SIZE - 1));
	index = tex_y * texture.len + tex_x * (texture.bpp / 8);
	return (*(int *)(texture.addr + index));
}

int	get_texture_color(t_game *game, t_ray *ray, int tex_x, int tex_y)
{
	t_texture	texture;
	int			index;

	if (ray->side == 1)
	{
		if (ray->dir_y > 0)
			set_textures(&texture, game->south->addr, game->south->len,
				game->south->bpp);
		else
			set_textures(&texture, game->north->addr, game->north->len,
				game->north->bpp);
	}
	else
	{
		if (ray->dir_x > 0)
			set_textures(&texture, game->east->addr, game->east->len,
				game->east->bpp);
		else
			set_textures(&texture, game->west->addr, game->west->len,
				game->west->bpp);
	}
	tex_x = fmax(0, fmin(tex_x, TEX_SIZE - 1));
	tex_y = fmax(0, fmin(tex_y, TEX_SIZE - 1));
	index = tex_y * texture.len + tex_x * (texture.bpp / 8);
	return (*(int *)(texture.addr + index));
}

int	calculate_tex_x(t_game *game, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEX_SIZE);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		tex_x = TEX_SIZE - tex_x - 1;
	return (tex_x);
}

int	calculate_tex_y(t_ray *ray, int y)
{
	int	tex_y;
	int	d;

	d = y * 256 - Y_RES * 128 + ray->line_height * 128;
	tex_y = ((d * TEX_SIZE) / ray->line_height) / 256;
	return (tex_y);
}
