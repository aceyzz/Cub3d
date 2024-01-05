/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:43:47 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 19:43:58 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		errmsg("Nombre d'argument invalide", false, NULL);
	if (!argv[1])
		errmsg("Argument invalide", false, NULL);
	if (ft_strlen(argv[1]) < 5)
		errmsg("Fichier invalide", false, NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		errmsg("Extension du fichier invalide", false, NULL);
	if (open(argv[1], O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier", false, NULL);
}
