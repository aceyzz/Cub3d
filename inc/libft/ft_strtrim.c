/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:26:23 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 20:27:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Crée une nouvelle chaîne de caractères en supprimant    */
/*   les caractères présents dans 'set' au début et à la fin de 's1'.         */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s1 : La chaîne de caractères à trimmer                              */
/*      - set : La chaîne de caractères contenant les caractères à supprimer  */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Une nouvelle chaîne de caractères allouée dynamiquement             */
/*        contenant la version trimmée de 's1'.                               */
/* *****************************************************************   by.XVI */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr((char *)set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr((char *)set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
