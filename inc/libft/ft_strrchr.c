/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:37:35 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:46:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Recherche la dernière occurrence du caractère 'c' dans  */
/*   la chaîne de caractères 's'.                                             */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères dans laquelle rechercher                */
/*      - c : Le caractère à rechercher                                       */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la dernière occurrence de 'c' dans 's' si elle     */
/*        est trouvée, sinon NULL.                                            */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*copy_s;
	unsigned char	ch;
	size_t			size;

	ch = c;
	size = ft_strlen(s);
	copy_s = (char *)s + size;
	if (ch == '\0')
		return (copy_s++);
	while (copy_s >= s)
	{
		if (*copy_s == ch)
			return (copy_s);
		copy_s--;
	}
	copy_s = NULL;
	return (copy_s);
}
