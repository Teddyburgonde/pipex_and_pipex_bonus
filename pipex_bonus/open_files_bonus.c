/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:56:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/20 16:09:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_files(int argc, t_vars *vars, char **argv)
{
	if (!is_here_doc(argv[1]))
	{
		vars->fd_infile = open(argv[1], O_RDONLY);
		vars->fd_outfile = open(argv[argc -1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
		vars->fd_outfile = open(argv[argc -1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (vars->fd_infile == -1 || vars->fd_outfile == -1)
	{
		perror("Error opening files");
		exit(1);
	}
}

void	check_infile(char **argv)
{
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0
		|| access(argv[1], W_OK) != 0)
	{
		ft_putstr_fd("Error\nPermission denied\n", 2);
		exit(1);
	}
}

void	verif_tab(char *tab)
{
	if (!tab)
	{
		ft_putstr_fd("Error\n No limiter for heredoc", 2);
		exit(1);
	}
}

void	open_fd_infile(t_vars *vars)
{
	vars->fd_infile = open("TMP_HEREDOC", O_RDONLY, 0644);
	if (!vars->fd_infile)
	{
		perror("Error opening files");
		exit(1);
	}
	unlink("TMP_HEREDOC");
}

void	open_hd_w(t_vars *vars)
{
	vars->hd_w = open("TMP_HEREDOC", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->hd_w == -1)
	{
		perror("Error opening files");
		exit(1);
	}
}
