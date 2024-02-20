/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:08:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/19 15:05:43 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	wd_count_word(char const *str, char separator)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != separator)
			i++;
	}
	return (count);
}

char	*ft_substr_split(char const *s, unsigned int start, int len)
{
	int		i;
	int		j;
	char	*tab;

	tab = NULL;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (NULL);
	j = ft_strlen(s + start);
	if (j < len)
		len = j;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	initialize_variables(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

char	**ft_split(char const *str, char separator)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	initialize_variables(&i, &j, &k);
	tab = ft_calloc(wd_count_word(str, separator) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		k = i;
		while (str[k] && str[k] != separator)
			k++;
		if (k - i != 0)
			tab[j] = ft_substr_split(str, i, k - i);
		i = k;
		while (str[i] && str[i] == separator)
			i++;
		j++;
	}
	tab[wd_count_word(str, separator)] = NULL;
	return (tab);
}
