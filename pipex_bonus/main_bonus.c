/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/20 17:15:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;
	int		i;

	i = 2;
	ft_parsing(argc, envp);
	if (is_here_doc(argv[1]))
		ft_heredoc(&vars, argv);
	else
		check_infile(argv);
	open_files(argc, &vars, argv);
	if (is_here_doc(argv[1]))
		vars.nb_cmd = argc -4;
	else
		vars.nb_cmd = argc -3;
	vars.path = grep_path(envp);
	vars.cmd = ft_calloc(vars.nb_cmd + 1, sizeof(char **));
	verif_fill_command_paths(&vars, argv);
	vars.tmp_fd = -1;
	i = 0;
	fork_processes(&vars, envp);
	ft_free(vars.path);
	ft_free_tab_3d(&vars);
	ft_close_fd(&vars);
	while (waitpid(-1, NULL, 0) != -1)
		continue ;
}
