/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:54:09 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:44:55 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Écrit la chaîne de caractères 's' suivie d'un saut de   */
/*   ligne dans le descripteur de fichier 'fd'.                               */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères à écrire                                */
/*      - fd : Le descripteur de fichier où écrire la chaîne et le saut de    */
/*        ligne                                                               */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
