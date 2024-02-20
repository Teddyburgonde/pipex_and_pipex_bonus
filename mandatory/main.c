/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/19 17:22:34 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;

	if (!envp || !envp[0])
		exit(1);
	if (argc != 5)
	{
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	open_files(&vars, argv);
	vars.paths = grep_path(envp);
	verif_paths(&vars);
	vars.final_path1 = find_the_accessible_path(vars.paths, argv[2]);
	if (!vars.final_path1)
		close(vars.fd_infile);
	vars.final_path2 = find_the_accessible_path(vars.paths, argv[3]);
	error_vars_final_path2(&vars);
	if (pipe(vars.pipe) == -1)
		return (-1);
	execute_child_parent_processes(&vars, envp);
	ft_full_free(&vars);
}
