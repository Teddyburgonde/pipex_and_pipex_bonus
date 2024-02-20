/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:05:51 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/08 10:32:44 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_full_free(t_vars *vars)
{
	ft_free(vars->paths);
	ft_free(vars->final_path1);
	ft_free(vars->final_path2);
}
