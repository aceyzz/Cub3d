/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:53:44 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 20:02:31 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Alloue et retourne une nouvelle chaîne de caractères    */
/*   résultant de la concaténation de 's1' suivi de 's2'.                     */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s1 : La première chaîne de caractères                               */
/*      - s2 : La deuxième chaîne de caractères                               */
/*                                                                            */
/*   Retour :                                                                 */
/*      Un pointeur vers la nouvelle chaîne de caractères, ou NULL si         */
/*      l'allocation échoue.                                                  */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!dest)
		return (NULL);
	if (s1)
		while (s1[++i])
			dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (dest);
}
