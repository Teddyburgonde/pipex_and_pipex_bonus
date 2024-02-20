/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:20:54 by tebandam          #+#    #+#             */
/*   Updated: 2023/11/22 08:20:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_loop(char *buf, char *stock, int *len, int fd)
{
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	*len = read(fd, buf, BUFFER_SIZE);
	if (*len == -1 || (*len == 0 && stock[0] == '\0'))
	{
		free(buf);
		free(stock);
		return (NULL);
	}
	buf[*len] = 0;
	stock = ft_strjoin(stock, buf);
	free(buf);
	buf = NULL;
	return (stock);
}

static char	*read_line(int fd, char *stock)
{
	char	*buf;
	int		len;

	len = 1;
	buf = NULL;
	if (stock != NULL)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = 0;
		if (len > 0)
			stock = ft_strjoin(stock, buf);
		free(buf);
		buf = NULL;
	}
	else
	{
		stock = malloc(sizeof(char));
		stock[0] = 0;
	}
	while (len > 0 && ft_strchr(stock, '\n') == NULL)
		stock = read_loop(buf, stock, &len, fd);
	free(buf);
	return (stock);
}

static char	*extract_line(char *stock)
{
	int		i;
	char	*line;

	line = NULL;
	if (stock == NULL)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = ft_substr(stock, 0, i);
	return (line);
}

static char	*extract_surplus_line(char *stock)
{
	int		i;
	int		j;
	char	*new_stock;

	if (stock == NULL)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	j = ft_strlen(stock);
	if (i == j)
	{
		free(stock);
		return (NULL);
	}
	new_stock = ft_substr(stock, i, j);
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = read_line(fd, stock[fd]);
	line = extract_line(stock[fd]);
	stock[fd] = extract_surplus_line(stock[fd]);
	return (line);
}
