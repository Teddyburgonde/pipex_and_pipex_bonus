/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:29:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/20 17:05:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**grep_path(char **envp)
{
	char	**tmp;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (envp[i] != NULL)
	{
		tmp = ft_split(envp[i] + 5, ':');
		return (tmp);
	}
	return (NULL);
}

void	update_full_cmd(char ***full_cmd, char *is_valid_cmd)
{
	free((*full_cmd)[0]);
	(*full_cmd)[0] = NULL;
	(*full_cmd)[0] = malloc(ft_strlen(is_valid_cmd) + 1);
	ft_strlcpy((*full_cmd)[0], is_valid_cmd, ft_strlen(is_valid_cmd) + 1);
	free(is_valid_cmd);
}

void	build_path(char **path, char **bin_path,
	char **is_valid_cmd, char **full_cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		*bin_path = ft_strjoin(path[i++], "/");
		*is_valid_cmd = ft_strjoin(*bin_path, full_cmd[0]);
		free(*bin_path);
		if (access(*is_valid_cmd, X_OK) == 0)
		{
			update_full_cmd(&full_cmd, *is_valid_cmd);
			break ;
		}
		free(*is_valid_cmd);
	}
}

char	**find_the_accessible_path(char **path, char *command, t_vars *vars)
{
	int		i;
	int		arr_len;
	char	*bin_path;
	char	*is_valid_cmd;

	i = 0;
	arr_len = 0;
	vars->full_cmd = ft_split(command, ' ');
	if (vars->full_cmd == NULL || vars->full_cmd[0] == NULL
		|| vars->full_cmd[0][0] == '\0')
	{
		ft_putstr_fd("Error\nCmd invalid", 2);
		ft_free_tab_3d(vars);
		ft_free(vars->path);
		ft_free(vars->full_cmd);
		close(vars->fd_infile);
		close(vars->fd_outfile);
		exit(1);
	}
	arr_len = ft_array_len(vars->full_cmd);
	if (access(vars->full_cmd[0], X_OK) == 0)
		return (vars->full_cmd);
	build_path(path, &bin_path, &is_valid_cmd, vars->full_cmd);
	return (vars->full_cmd);
}

int	fill_command_paths(t_vars *vars, char **argv)
{
	int	configuration;
	int	i;

	if (is_here_doc(argv[1]))
		configuration = 3;
	else
		configuration = 2;
	i = configuration;
	while (i < vars->nb_cmd + configuration)
	{
		if (!argv[i] || !argv[i][0])
			return (-1);
		vars->cmd[i - configuration] = find_the_accessible_path(vars->path,
				argv[i], vars);
		if (vars->cmd[i - configuration] == NULL)
		{
			return (-1);
		}
		i++;
	}
	vars->cmd[i - configuration] = NULL;
	return (0);
}
