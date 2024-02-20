/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:53:02 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/09 18:26:38 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_ptr_hexa(unsigned long nb)
{
	char	*lowercase;
	int		print_length;

	print_length = 0;
	lowercase = "0123456789abcdef";
	if (!nb)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (nb >= 16)
		print_length = print_ptr_hexa(nb / 16);
	if (print_length == 0)
		print_length += write(1, "0x", 2);
	print_length += 1;
	write(1, &lowercase[nb % 16], 1);
	return (print_length);
}
