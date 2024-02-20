/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_lowercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:18:05 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/10 10:46:07 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hexa_lowercase(unsigned int nb)
{
	int		print_length;
	char	*lowercase;

	lowercase = "0123456789abcdef";
	print_length = 0;
	if (nb >= 16)
		print_length = ft_print_hexa_lowercase(nb / 16);
	print_length += 1;
	write(1, &lowercase[nb % 16], 1);
	return (print_length);
}
