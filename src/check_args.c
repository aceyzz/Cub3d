/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:02:39 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/07 13:14:22 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		errmsg("Nombre d'argument incorrect", false, NULL);
	if (ft_strlen(argv[1]) < 5
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		errmsg("Extension de fichier incorrecte", false, NULL);
	if (open(argv[1], O_RDONLY) == -1)
		errmsg("Impossible d'ouvrir le fichier", false, NULL);
}
