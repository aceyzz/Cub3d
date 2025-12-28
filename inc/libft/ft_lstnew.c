/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:47:20 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:44:05 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Crée un nouvel élément de liste avec la donnée passée   */
/*   en argument.                                                             */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - content : La donnée à stocker dans le nouvel élément de liste.      */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers le nouvel élément de liste créé.                   */
/*      - NULL en cas d'échec d'allocation de mémoire.                        */
/* *****************************************************************   by.XVI */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *) malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
