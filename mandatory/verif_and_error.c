/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:20:45 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/19 17:21:26 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	verif_paths(t_vars *vars)
{
	if (vars->paths == NULL)
	{
		ft_putstr_fd("Error\nInvalid path", 2);
		exit(1);
	}
}

void	error_vars_final_path2(t_vars *vars)
{
	if (!vars->final_path2)
	{
		ft_full_free(vars);
		close(vars->fd_infile);
		close(vars->fd_outfile);
		exit(1);
	}
}