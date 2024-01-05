/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:20:33 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/05 18:41:21 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_next(char c, va_list args, int *count)
{
	if (c == 'c')
		print_c(va_arg(args, int), count);
	else if (c == 's')
		print_s(va_arg(args, char *), count);
	else if (c == 'p')
	{
		(*count) += write(1, "0x", 2);
		print_p(va_arg(args, size_t), 16, count);
	}
	else if (c == 'd' || c == 'i')
		print_n((long long int)va_arg(args, int), 10, count, 0);
	else if (c == 'u')
		print_n((long long int)va_arg(args, unsigned int), 10, count, 0);
	else if (c == 'x')
		print_n((long long int)va_arg(args, unsigned int), 16, count, 0);
	else if (c == 'X')
		print_n((long long int)va_arg(args, unsigned int), 16, count, 1);
	else if (c == '%')
		print_s("%", count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			check_next(format[++i], args, &count);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
