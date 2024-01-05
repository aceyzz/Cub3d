/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:51:07 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:43:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Supprime un élément de la liste sans supprimer la       */
/*   structure de donnée qu'il contenait.                                     */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - lst : L'élément de liste à supprimer.                               */
/*      - del : La fonction à utiliser pour supprimer le contenu de lst.      */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
