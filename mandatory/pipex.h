/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:36:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/19 17:22:26 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_vars{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	char	**paths;
	char	*path;
	char	**final_path1;
	char	**final_path2;

	int		i;
	char	**full_cmd;
	char	*is_valid_cmd;
	char	*bin_path;
	size_t	arr_len;
}			t_vars;

char	**grep_path(char **envp);
char	**find_the_accessible_path(char **path, char *command);
void	child_process(t_vars *vars, char *envp[]);
void	second_child_process(t_vars *vars, char *envp[]);
void	parent_process(t_vars *vars, char *envp[]);
void	execute_child_parent_processes(t_vars *vars, char *envp[]);
void	ft_full_free(t_vars *vars);
void	open_files(t_vars *vars, char **argv);
void	verif_paths(t_vars *vars);
void	error_vars_final_path2(t_vars *vars);

#endif