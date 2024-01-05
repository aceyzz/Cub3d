/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:37:36 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:44:17 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Recherche la première occurrence de l'octet c dans les  */
/*   n premiers octets dans la zone mémoire pointée par s.                    */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : Un pointeur vers la zone mémoire à analyser                     */
/*      - c : L'octet à rechercher                                            */
/*      - n : Le nombre d'octets à analyser                                   */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la première occurrence de c dans s,                */
/*        ou NULL si c n'est pas trouvé.                                      */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
