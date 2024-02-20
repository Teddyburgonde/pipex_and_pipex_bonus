/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:13:03 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/11 16:35:38 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	format(char c, va_list list)
{
	int	print;

	print = 0;
	if (c == 's')
		print = ft_putstr(va_arg(list, char *));
	else if (c == 'c')
		print = ft_putchar(va_arg(list, int));
	else if (c == '%')
		print = write(1, "%", 1);
	else if (c == 'd' || c == 'i')
		print = ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		print = ft_unsigned_int_putnbr(va_arg(list, unsigned int));
	else if (c == 'p')
		print = print_ptr_hexa(va_arg(list, unsigned long));
	else if (c == 'x')
		print = ft_print_hexa_lowercase(va_arg(list, unsigned int));
	else if (c == 'X')
		print = ft_print_hexa_uppercase(va_arg(list, unsigned int));
	else
	{
		print += ft_putchar ('%');
		print += ft_putchar(c);
	}
	return (print);
}

int	ft_printf(char *str, ...)
{
	va_list		list;
	int			i;
	int			print;

	if (!str)
		return (-1);
	va_start(list, str);
	print = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += format(str[i + 1], list);
			i++;
		}
		else
			print += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (print);
}
