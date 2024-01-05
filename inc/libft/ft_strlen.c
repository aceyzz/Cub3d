/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:58:19 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:52 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Calcule la longueur de la chaîne de caractères 's'.     */
/*                                                                            */
/*   Paramètre :                                                              */
/*      - s : La chaîne de caractères dont on veut calculer la longueur.      */
/*                                                                            */
/*   Retour :                                                                 */
/*      La longueur de la chaîne 's' (c'est-à-dire le nombre de caractères    */
/*      dans 's', sans tenir compte du caractère nul de fin).                 */
/* *****************************************************************   by.XVI */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
