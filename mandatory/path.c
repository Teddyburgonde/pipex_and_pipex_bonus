/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:15:30 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/19 16:58:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	build_path(t_vars *vars, char **path)
{
	while (path[vars->i])
	{
		vars->bin_path = ft_strjoin(path[vars->i++], "/");
		vars->is_valid_cmd = ft_strjoin(vars->bin_path, vars->full_cmd[0]);
		free(vars->bin_path);
		if (access(vars->is_valid_cmd, X_OK) == 0)
		{
			update_full_cmd(&vars->full_cmd, vars->is_valid_cmd);
			break ;
		}
		free(vars->is_valid_cmd);
	}
}

char	**find_the_accessible_path(char **path, char *command)
{
	t_vars	vars;

	vars.i = 0;
	vars.full_cmd = ft_split(command, ' ');
	if (vars.full_cmd == NULL || vars.full_cmd[0] == NULL
		|| vars.full_cmd[0][0] == '\0')
	{
		ft_free(vars.full_cmd);
		return (NULL);
	}
	vars.arr_len = ft_array_len(vars.full_cmd);
	if (access(vars.full_cmd[0], X_OK) == 0)
		return (vars.full_cmd);
	build_path(&vars, path);
	return (vars.full_cmd);
}
