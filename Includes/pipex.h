/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:47:23 by nchabli           #+#    #+#             */
/*   Updated: 2022/05/03 16:22:49 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	int		infile;
	int		outfile;
	int		cmd;
	int		first_cmd;
	int		last_cmd;
	char	*limiter;
	char	**argv;
	char	**envp;
}	t_pipex;
/* 
typedef struct s_path {
	char	*path_from_envp;
	char	**mypath;
	char	**cmd_arg;
}				t_path; */

void	perror(const char *s);
int		control_entry(int ac, char **ag);
int		get_cmd_path(t_pipex *g, int func_no);
void	ft_execve(t_pipex *g);
char	*look_path(char *comand, t_pipex *g);
void	ft_error(void);

#endif