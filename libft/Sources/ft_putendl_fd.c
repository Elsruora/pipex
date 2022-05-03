/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:27:55 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/10 17:59:33 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = -1;
	c = '\n';
	if (s)
	{
		while (s[++i])
			write (fd, &s[i], 1);
		write (fd, &c, 1);
	}
}
