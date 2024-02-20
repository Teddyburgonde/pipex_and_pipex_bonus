/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:18:00 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/08 16:11:35 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;

	i = 0;
	last_occurence = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			last_occurence = (char *)(s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		last_occurence = (char *)(s + i);
	return (last_occurence);
}
