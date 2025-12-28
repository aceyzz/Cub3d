/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:51:29 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:48 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Copie la chaîne de caractères 'src' dans 'dst' avec     */
/*   une taille maximale de 'dstsize'. Si 'dstsize' est supérieur à la        */
/*   longueur de 'src', la fonction copie toute la chaîne 'src' dans 'dst'    */
/*   et ajoute un caractère nul à la fin. Sinon, elle copie 'dstsize - 1'     */
/*   caractères de 'src' dans 'dst' et ajoute un caractère nul à la fin.      */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - dst : La chaîne de caractères de destination                        */
/*      - src : La chaîne de caractères source à copier                       */
/*      - dstsize : La taille maximale de 'dst'                               */
/*                                                                            */
/*   Retour :                                                                 */
/*      La longueur de la chaîne 'src' (c'est-à-dire le nombre de caractères  */
/*      dans 'src', sans tenir compte du caractère nul de fin).               */
/* *****************************************************************   by.XVI */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
