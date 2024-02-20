/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:19:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/19 17:20:00 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_vars *vars, char **argv)
{
	vars->infile = argv[1];
	vars->outfile = argv[4];
	vars->fd_infile = open(vars->infile, O_RDONLY);
	vars->fd_outfile = open(vars->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->fd_outfile == -1)
	{
		if (vars->fd_infile)
			close(vars->fd_infile);
		perror("Error opening files");
		exit(1);
	}
}