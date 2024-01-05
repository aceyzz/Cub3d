/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:18:29 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:10 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Remplit les n premiers octets de la mémoire pointée par */
/*   s avec l'octet nul (valeur 0).                                           */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : Un pointeur vers la mémoire à remplir                           */
/*      - n : Le nombre d'octets à remplir                                    */
/*                                                                            */
/*   Retour :                                                                 */
/*      Aucun                                                                 */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
