/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:37:33 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:17 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Duplique une chaîne de caractères 's1' dans une         */
/*   nouvelle allocation mémoire.                                             */
/*                                                                            */
/*   Paramètre :                                                              */
/*      - s1 : La chaîne de caractères à dupliquer                            */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la nouvelle chaîne de caractères dupliquée.        */
/*      - NULL en cas d'échec d'allocation mémoire.                           */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
