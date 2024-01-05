/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:17:22 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Fonctionnement :  Convertit une chaîne de caractères en int.               */
/* Paramètre :       Chaîne de caractères str.                                */
/* Retour :          Un int.                                                  */
/* Si échec :        La fonction renvoie 0 si la chaîne ne contient pas       */
/*                   de chiffres valides ou si le résultat dépasse la plage   */
/*                   d'un int.                                                */
/* *****************************************************************   by.XVI */
#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	resultat;
	long	signe;

	i = 0;
	resultat = 0;
	signe = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] && str[i] == '-')
	{
		signe = -signe;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		resultat = (str[i] - '0') + (resultat * 10);
		i++;
	}
	return (resultat * signe);
}
