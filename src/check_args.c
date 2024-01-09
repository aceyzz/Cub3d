/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:02:39 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/09 08:59:37 by cedmulle         ###   ########.fr       */
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

char	*remove_spaces(char *str)
{
	char	*result;
	int		i;
	size_t	len;

	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			len++;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			result[len++] = str[i];
	}
	result[len] = '\0';
	free(str);
	return (result);
}
