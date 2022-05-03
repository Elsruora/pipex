/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:35:48 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/10 17:59:30 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

void	ft_putnbr_fd(long n, int fd, int *c_count)
{
	if (n <= 9 && n >= 0)
	{
		ft_putchar_fd(n + '0', fd, c_count);
	}
	else if (n < 0)
	{
		ft_putchar_fd ('-', fd, c_count);
		ft_putnbr_fd (n * (-1), fd, c_count);
	}
	else
	{
		ft_putnbr_fd (n / 10, fd, c_count);
		ft_putnbr_fd (n % 10, fd, c_count);
	}
}

void	ft_putnbr_fd_hexa(unsigned long n, int fd, int *c_count, char *base)
{
	if (n < 16 && n >= 0)
		ft_putchar_fd(base[n], fd, c_count);
	else
	{
		ft_putnbr_fd_hexa (n / 16, fd, c_count, base);
		ft_putnbr_fd_hexa (n % 16, fd, c_count, base);
	}
}
