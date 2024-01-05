/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:22:02 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:44:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Remplit les len premiers octets de la zone mémoire      */
/*   pointée par b avec la valeur c (convertie en unsigned char).             */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - b : Un pointeur vers la zone mémoire à remplir                      */
/*      - c : La valeur à copier (convertie en unsigned char)                 */
/*      - len : Le nombre d'octets à remplir                                  */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la zone mémoire remplie (b).                       */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
