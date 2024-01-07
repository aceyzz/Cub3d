/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:23:37 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/07 14:27:03 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Divise une chaîne de caractères en mots en utilisant    */
/*   le caractère 'c' comme séparateur.                                       */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - s : La chaîne de caractères à diviser                               */
/*      - c : Le caractère de séparation                                      */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un tableau de chaînes de caractères contenant les mots extraits de  */
/*        's'. Le tableau est terminé par un pointeur NULL.                   */
/*      - NULL en cas d'échec (allocation mémoire ou paramètre invalide).     */
/*                                                                            */
/*   Si échec :                                                               */
/*      - La fonction renvoie NULL si l'allocation mémoire échoue ou si 's'   */
/*        est NULL.                                                           */
/* *****************************************************************   by.XVI */
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	int		index;
	char	**result;

	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	k = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			result[k++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	result[k] = 0;
	return (result);
}
