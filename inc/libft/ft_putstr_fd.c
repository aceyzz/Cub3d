/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:49:41 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:06 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Écrit la chaîne de caractères 's' dans le descripteur   */
/*   de fichier 'fd'.                                                         */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères à écrire                                */
/*      - fd : Le descripteur de fichier où écrire la chaîne de caractères.   */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
