/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:13:49 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:46:22 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Crée une nouvelle chaîne de caractères qui est une      */
/*   sous-chaîne de 's', débutant à l'index 'start' et d'une longueur 'len'.  */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères source                                  */
/*      - start : L'index de départ pour la sous-chaîne                       */
/*      - len : La longueur de la sous-chaîne                                 */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Une nouvelle chaîne de caractères allouée dynamiquement             */
/*        contenant la sous-chaîne de 's'.                                    */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}
