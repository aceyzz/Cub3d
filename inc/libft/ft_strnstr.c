/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:41:30 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:46:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Recherche une sous-chaîne 'needle' dans une chaîne de   */
/*   caractères 'haystack' en vérifiant selon 'len' caractères.               */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - haystack : La chaîne de caractères dans laquelle rechercher         */
/*      - needle : La sous-chaîne à rechercher                                */
/*      - len : Le nombre maximum de caractères à vérifier dans 'haystack'    */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la première occurrence de 'needle' dans 'haystack' */
/*        si elle est trouvée, sinon NULL.                                    */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j < len) && (haystack[i + j] == needle[j]))
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
