/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:57:42 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/18 16:59:46 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	capture_and_redirection(char *tab, char *tmp, t_vars *vars)
{
	while (ft_strncmp(tab, tmp, ft_strlen(tmp)))
	{
		ft_putstr_fd(tab, vars->hd_w);
		free(tab);
		write(1, "> ", 2);
		tab = get_next_line(STDIN_FILENO);
		if (!tab)
		{
			ft_putstr_fd("Error\n No limiter for heredoc", 2);
			exit(1);
		}
	}
	free(tab);
	free(tmp);
	close(vars->hd_w);
}

void	ft_heredoc(t_vars *vars, char **argv)
{
	char	*tmp;
	char	*tab;
	int		i;

	i = 0;
	tab = NULL;
	tmp = malloc(sizeof(char) * ft_strlen(argv[2]) + 2);
	while (argv[2][i] != '\0')
	{
		tmp[i] = argv[2][i];
		i++;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	open_hd_w(vars);
	write(1, "> ", 2);
	tab = get_next_line(STDIN_FILENO);
	verif_tab(tab);
	capture_and_redirection(tab, tmp, vars);
	close(vars->hd_w);
	open_fd_infile(vars);
}
