/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:53:13 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:44:25 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Fonctionnement : Copie les n premiers octets de la zone mémoire pointée  */
/*   par src dans la zone mémoire pointée par dst.                            */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - dst : Un pointeur vers la zone mémoire de destination               */
/*      - src : Un pointeur vers la zone mémoire source à copier              */
/*      - n : Le nombre d'octets à copier                                     */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la zone mémoire de destination (dst).              */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
