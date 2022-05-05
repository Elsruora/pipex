/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:18:15 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/10 17:59:28 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd, int *c_count)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd, c_count);
	}
}
