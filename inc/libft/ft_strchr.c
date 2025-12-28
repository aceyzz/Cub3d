/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:32:47 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 20:24:40 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Recherche la première occurrence du caractère 'c' dans  */
/*   la chaîne de caractères 's'.                                             */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères dans laquelle effectuer la recherche    */
/*      - c : Le caractère à rechercher                                       */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la première occurrence de 'c' dans 's'.            */
/*      - NULL si 'c' n'est pas trouvé dans 's'.                              */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
