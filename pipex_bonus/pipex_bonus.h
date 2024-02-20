/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/20 17:14:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H 

# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars{
	pid_t	child;
	int		fd_infile;
	int		fd_outfile;
	int		nb_cmd;
	int		heredoc;
	char	**path;
	char	***cmd;
	char	**full_cmd;
	int		pipe_1[2];
	int		tmp_fd;
	int		hd_w;
	int		hd_r;
}	t_vars;

char	**grep_path(char **envp);
void	ft_heredoc(t_vars *vars, char **argv);
int		is_here_doc(char *argv);
void	open_files(int argc, t_vars *vars, char **argv);
void	check_infile(char **argv);
void	child_process(t_vars *vars, char *envp[], int actual_cmd);
void	fork_processes(t_vars *vars, char *envp[]);
void	ft_parsing(int argc, char *envp[]);
int		fill_command_paths(t_vars *vars, char **argv);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_array_len(char **arr);
void	*ft_memset(void *s, int c, size_t n);
void	ft_free_tab_3d(t_vars *vars);
void	ft_close_fd(t_vars *vars);
void	open_fd_infile(t_vars *vars);
void	verif_tab(char *tab);
void	open_hd_w(t_vars *vars);
char	*ft_strdup(const char *s);
char	**find_the_accessible_path(char **path, char *command, t_vars *vars);
void	verif_fill_command_paths(t_vars *vars, char **argv);
#endif
