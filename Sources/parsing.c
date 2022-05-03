/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:10:05 by nchabli           #+#    #+#             */
/*   Updated: 2022/05/03 10:50:24 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

char	*look_path(char *comand, t_pipex *g)
{
	int		i;
	char	**all_path;
	char	*part_path;
	char	*path;

	i = 0;
	while (ft_strnstr(g->envp[i], "PATH", 4) == 0)
		i++;
	all_path = ft_split(g->envp[i] + 5, ':');
	i = 0;
	while (all_path[i])
	{
		part_path = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(part_path, comand);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	ft_execve(t_pipex *g)
{
	char	**comand;
	char	*path;

	comand = ft_split(g->argv[g->cmd], ' ');
	path = look_path(comand[0], g);
	if (execve(path, comand, g->envp) == -1)
		ft_error();
}

/* int	get_cmd_path(t_pipex *g, int func_no)
{
	t_path	p;
	char	*cmdpath;
	char	**cmdargs;
	int		i;
	char	*tmp;

	i = -1;
	cmdargs = ft_split(g->cmd, ' ');
	p.path_from_envp = ft_search_envp_path(g->envp);
	p.mypath = ft_split(p.path_from_envp, ':');
	while (p.mypath[++i])
	{
		tmp = ft_strjoin(p.mypath[i], "/");
		cmdpath = ft_strjoin(tmp, cmdargs[0]);
		free(tmp);
		execve(cmdpath, cmdargs, g->envp);
		free(cmdpath);
	}
	return (EXIT_FAILURE);
} */
	//free_split(cmdargs);