/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:53:26 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 18:41:11 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_c(int c, int *count)
{
	(*count) += write(1, &c, 1);
}

void	print_s(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		(*count) += write(1, &str[i++], 1);
}

void	print_p(size_t nb, int base, int *count)
{
	if (nb > (size_t)base - 1)
		print_p(nb / base, base, count);
	if (nb % base < 10)
		print_c(nb % base + '0', count);
	else
		print_c(nb % base + 'a' - 10, count);
}

void	print_n(long long int nbr, int base, int *count, int maj)
{
	char	*str_base;

	if (maj)
		str_base = "0123456789ABCDEF";
	else
		str_base = "0123456789abcdef";
	if (nbr < 0)
	{
		(*count) += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > base - 1)
		print_n(nbr / base, base, count, maj);
	(*count) += write(1, &str_base[nbr % base], 1);
	return ;
}
