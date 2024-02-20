/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:41:20 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/08 10:27:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_unsigned_int_putnbr(unsigned int n)
{
	int	print;

	print = 0;
	if (n > 9)
		print = ft_unsigned_int_putnbr(n / 10);
	print += ft_putchar((n % 10) + '0');
	return (print);
}

int	ft_putnbr(int nb)
{
	int	print;
	int	negative;

	print = 0;
	negative = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
		negative = 1;
	}
	if (nb > 9)
		print = ft_putnbr(nb / 10);
	print += ft_putchar((nb % 10) + '0');
	if (negative)
		return (print + 1);
	return (print);
}
