/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:34:12 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:45:41 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Concatène la chaîne de caractères 'src' à la fin de     */
/*   'dst' en prenant en compte la taille maximale de 'dst'.                  */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - dst : La chaîne de caractères de destination                        */
/*      - src : La chaîne de caractères source à concaténer                   */
/*      - size : La taille maximale de 'dst'                                  */
/*                                                                            */
/*   Retour :                                                                 */
/*      La longueur totale de la chaîne de caractères résultante (cad         */
/*      la somme de la longueur de 'dst' et 'src' avant concaténation).       */
/*      Si la longueur totale est supérieure ou égale à 'size', la valeur     */
/*      retournée est 'size + ft_strlen(src)', sinon elle est                 */
/*      'ft_strlen(dst) + ft_strlen(src)'.                                    */
/* *****************************************************************   by.XVI */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*str;
	size_t	len_dst;
	size_t	result;
	size_t	len_src;
	size_t	i;

	str = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(str);
	result = 0;
	i = 0;
	if (size > len_dst)
		result = len_src + len_dst;
	else
		result = len_src + size;
	while (str[i] && (len_dst + 1) < size)
	{
		dst[len_dst] = str[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (result);
}
