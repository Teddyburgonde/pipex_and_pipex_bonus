/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_uppercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:43:18 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/10 11:11:42 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hexa_uppercase(unsigned int nb)
{
	char	*uppercase;
	int		print_length;

	print_length = 0;
	uppercase = "0123456789ABCDEF";
	if (nb >= 16)
		print_length = ft_print_hexa_uppercase(nb / 16);
	print_length += 1;
	write(1, &uppercase[nb % 16], 1);
	return (print_length);
}
