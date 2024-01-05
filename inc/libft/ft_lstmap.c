/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:43:11 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:43:02 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Applique la fonction 'f' à chaque élément de la liste,  */
/*   crée une nouvelle liste avec les résultats et retourne un pointeur vers  */
/*   la nouvelle lst. En cas d'échec d'allocation mémoire, libère la nouvelle */
/*   liste ainsi que son contenu en utilisant 'del' et renvoie NULL.          */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - lst : Un pointeur vers le premier élément de la liste à mapper.     */
/*      - f : La fonction à appliquer à chaque élément de la liste.           */
/*      - del : La fonction à utiliser pour supprimer le contenu en cas       */
/*              d'échec d'allocation mémoire.                                 */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers la nouvelle liste créée.                           */
/*      - NULL en cas d'échec d'allocation mémoire ou si 'lst' est NULL.      */
/*                                                                            */
/*   Si échec :                                                               */
/*      La fonction libère la nouvelle liste ainsi que son contenu en cas     */
/*      d'échec d'allocation mémoire et renvoie NULL.                         */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcontent;

	if (lst == NULL)
		return (NULL);
	newlst = 0;
	while (lst != NULL)
	{
		newcontent = ft_lstnew(((*f)(lst->content)));
		if (newcontent == NULL)
		{
			ft_lstclear(&newcontent, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newcontent);
		lst = lst->next;
	}
	return (newlst);
}
