/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:34:09 by nchabli           #+#    #+#             */
/*   Updated: 2022/04/23 13:29:30 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

int	control_entry(int ac, char **ag)
{
	(void)ag;
	if (ac != 5)
	{
		ft_error();
		return (0);
	}
	if (ft_have_print(ag[2]) == 1 || ft_have_print(ag[3]) == 1)
	{
		ft_error();
		return (0);
	}
	return (1);
}
