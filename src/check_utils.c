/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:59:00 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/09 09:07:53 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	is_empty_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (false);
	}
	return (true);
}

int	tab_size(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (!is_empty_line(tab[i]))
			count++;
		i++;
	}
	return (count);
}
