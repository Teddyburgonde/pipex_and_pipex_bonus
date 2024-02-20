/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:22:21 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/10 10:38:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(char *str, ...);
int				ft_putstr(char *str);
int				ft_putchar(char c);
int				ft_print_hexa_lowercase(unsigned int nb);
int				ft_print_hexa_uppercase(unsigned int nb);
int				print_ptr_hexa(unsigned long nb);
int				ft_unsigned_int_putnbr(unsigned int n);
int				ft_putnbr(int nb);

#endif