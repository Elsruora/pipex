/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:37:17 by nchabli           #+#    #+#             */
/*   Updated: 2022/05/03 16:38:07 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_childs(t_pipex *g)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1 && g->cmd < g->last_cmd)
		ft_error();
	if (pid == 0 && g->cmd != g->last_cmd)
	{
		if (g->first_cmd == g->cmd)
		{
			close(fd[0]);
			if (dup2(g->infile, STDIN_FILENO) < 0)
				ft_error();
		}
		if (g->cmd == g->last_cmd && dup2(g->outfile, STDOUT_FILENO) < 0)
			ft_error();
		else
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execve(g);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	init_g(int ac, char **av, char **envp, t_pipex *g)
{
	int		fd[2];
	char	*str;

	g->argc = ac;
	g->argv = av;
	g->envp = envp;
	g->last_cmd = ac - 2;
	g->cmd = 2;
	g->first_cmd = g->cmd;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		g->limiter = av[2];
		g->cmd++;
		pipe(fd);
		while (str != g->limiter || str == NULL)
			str = get_next_line(STDIN_FILENO);
			ft_putstr_fd(str, fd[1]);
		g->infile = fd[0];
	}
	else
	{
		g->infile = open(av[1], O_RDONLY, 0777);
		g->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	if (g->infile < 0)
		g->cmd++;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	g;

	if (ac >= 5)
	{
		init_g(ac, av, envp, &g);
		while (g.cmd <= g.last_cmd)
		{
			ft_childs(&g);
			g.cmd++;
		}
		g.cmd = 2;
		while (g.cmd++ <= g.last_cmd)
			waitpid(-1, NULL, 0);
	}
	else
	{
		ft_putstr("\033[31mError: usage: \"\
./pipex file1 cmd1 cmd2 (...) file2\"\n");
		exit(EXIT_FAILURE);
	}
	close(g.infile);
	close(g.outfile);
	while (1);
}
