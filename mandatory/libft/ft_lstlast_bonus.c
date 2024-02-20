/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:52:01 by tebandam          #+#    #+#             */
/*   Updated: 2023/10/30 12:52:06 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_last_element;

	if (!lst)
		return (NULL);
	ptr_last_element = lst;
	while (ptr_last_element->next != NULL)
	{
		ptr_last_element = ptr_last_element->next;
	}
	return (ptr_last_element);
}
