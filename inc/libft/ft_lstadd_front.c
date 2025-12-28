/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:58:34 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:43:57 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Ajoute un nouvel élément en tête de la liste chaînée.   */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - lst : Un pointeur vers un pointeur de liste, qui pointe vers la     */
/*              tête de la liste à laquelle ajouter l'élément.                */
/*      - new : Un pointeur vers l'élément de liste à ajouter en tête.        */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
