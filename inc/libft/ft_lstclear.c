/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:58:36 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Supprime et libère la mémoire de tous les éléments de   */
/*   la liste en utilisant la fonction de suppression 'del'.                  */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - lst : Un pointeur vers un pointeur de liste. Lorsque la fonction    */
/*              termine, 'lst' est défini à NULL pour indiquer que la liste   */
/*              est maintenant vide.                                          */
/*      - del : Un pointeur vers une fonction qui prend un argument de type   */
/*              'void *' et libère la mémoire associée à cet argument.        */
/* *****************************************************************   by.XVI */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy_lst;
	t_list	*next_lst;

	copy_lst = *lst;
	while (copy_lst != NULL)
	{
		next_lst = copy_lst->next;
		ft_lstdelone(copy_lst, del);
		copy_lst = next_lst;
	}
	*lst = NULL;
}
