/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:29:13 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/09 12:30:29 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define RST "\033[0m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;34m"
# define MAG "\033[1;35m"
# define CYA "\033[1;36m"
# define WHT "\033[1;37m"

# define X_RES 1920
# define Y_RES 1080

typedef struct s_settings
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceil;
	bool	fl_ispath;
	bool	cl_ispath;
	int		fl_rgb[3];
	int		cl_rgb[3];
}			t_settings;

typedef struct s_game
{
	int			fd;
	char		*filename;
	char		*filecontent_str;
	size_t		filecontent_size;
	char		**file_tab;
	t_settings	*settings;
	char		**map;
}				t_game;

/* free.c */
void	free_ptr(void *ptr);
void	free_tab(char **tab);
void	free_data(t_game *game);
/* exit.c */
void	errmsg(const char *errmsg, bool to_free, t_game *game);
void	exit_game(t_game *game);
/* check_args.c */
void	check_args(int argc, char **argv);
char	*remove_spaces(char *str);
/* check_settings.c */
void	check_settings(t_game *game);
/* check_map.c */
void	check_map(t_game *game);
/* check_utils.c */
int		tab_size(char **tab);
bool	is_empty_line(char *line);
/* init_data.c */
void	init_data(t_game **game, char **argv);
/* init_rgb.c */
void	init_rgb(t_game *game);
/* init_map.c */
void	parse_map(t_game *game);

#endif
