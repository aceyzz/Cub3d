/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:01:59 by cedmulle          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:40 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Convertit un entier en une chaîne de caractères.        */
/*                                                                            */
/*   Paramètre :                                                              */
/*      - n : L'entier à convertir                                            */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un pointeur vers une nouvelle chaîne de caractères représentant n.  */
/*      - NULL en cas d'échec d'allocation mémoire.                           */
/* *****************************************************************   by.XVI */
#include "libft.h"

static unsigned int	ft_intlen(int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		len += 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	number;
	unsigned int	size;

	size = ft_intlen(n);
	result = (char *)malloc(sizeof(char) * (size) + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		result[0] = '0';
	result[size] = '\0';
	while (number != 0)
	{
		result[size - 1] = (number % 10) + '0';
		number = number / 10;
		size--;
	}
	return (result);
}
