/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/18 16:46:54 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_processes(t_vars *vars, char *envp[])
{
	int	i;

	i = 0;
	while (i < vars->nb_cmd)
	{
		if (pipe(vars->pipe_1) == -1)
			exit(EXIT_FAILURE);
		vars->child = fork();
		if (vars->child == 0)
			child_process(vars, envp, i);
		else if (vars->child < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (vars->tmp_fd != -1)
				close(vars->tmp_fd);
			vars->tmp_fd = dup(vars->pipe_1[0]);
			close(vars->pipe_1[0]);
			close(vars->pipe_1[1]);
		}
		i++;
	}
}

void	ft_flow_redirection(t_vars *vars, int actual_cmd)
{
	if (actual_cmd == 0)
	{
		if (dup2(vars->fd_infile, STDIN_FILENO) < 0)
			perror("dup2");
		if (dup2(vars->pipe_1[1], STDOUT_FILENO) < 0)
			perror("dup2");
	}
	else if (actual_cmd == vars->nb_cmd - 1)
	{
		if (dup2(vars->tmp_fd, STDIN_FILENO) < 0)
			perror("dup2");
		if (dup2(vars->fd_outfile, STDOUT_FILENO) < 0)
			perror("dup2");
	}
	else
	{
		if (dup2(vars->tmp_fd, STDIN_FILENO) < 0)
			perror("dup2");
		if (dup2(vars->pipe_1[1], STDOUT_FILENO) < 0)
			perror("dup2");
	}
}

void	child_process(t_vars *vars, char *envp[], int actual_cmd)
{
	ft_flow_redirection(vars, actual_cmd);
	if (vars->tmp_fd != -1)
		close(vars->tmp_fd);
	close(vars->pipe_1[0]);
	close(vars->pipe_1[1]);
	close(vars->fd_infile);
	close(vars->fd_outfile);
	execve(vars->cmd[actual_cmd][0], vars->cmd[actual_cmd], envp);
	perror("Execve");
	ft_free(vars->path);
	ft_free_tab_3d(vars);
	exit(1);
}
