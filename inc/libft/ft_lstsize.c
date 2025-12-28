/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:17:22 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:44:13 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Calcule la taille de la liste chaînée.                  */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - lst : Un pointeur vers la tête de la liste chaînée dont on veut     */
/*              calculer la taille.                                           */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Le nombre d'éléments dans la liste chaînée.                         */
/* *****************************************************************   by.XVI */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}
