/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 07:48:54 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/10 18:02:20 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	ft_strputter(char *s, int *c_count)
{
	if (s == NULL)
		ft_putstr_fd("(null)", 1, c_count);
	else
		ft_putstr_fd(s, 1, c_count);
}

void	write_with_args(char c, va_list params, int *c_count)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(params, int), 1, c_count);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(params, int), 1, c_count);
	if (c == 's')
		ft_strputter(va_arg(params, char *), c_count);
	if (c == 'x')
		ft_putnbr_fd_hexa(va_arg(params, unsigned int), 1, c_count, \
		"0123456789abcdef");
	if (c == 'X')
		ft_putnbr_fd_hexa(va_arg(params, unsigned int), 1, c_count, \
		"0123456789ABCDEF");
	if (c == 'u')
		ft_putnbr_fd(va_arg(params, unsigned int), 1, c_count);
	if (c == '%')
		ft_putchar_fd('%', 1, c_count);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1, c_count);
		ft_putnbr_fd_hexa(va_arg(params, unsigned long), 1, c_count, \
		"0123456789abcdef");
	}
}

void	check_save_signs(const char *save, va_list params, int *c_count)
{
	int		i;

	i = 0;
	while (save[i])
	{
		if (save[i] != '%')
		{
			ft_putchar_fd(save[i], 1, c_count);
			i++;
		}
		else
		{
			write_with_args (save[++i], params, c_count);
			i++;
		}
	}
}

int	ft_printf(const char *save, ...)
{	
	int			c_count;
	va_list		params;

	c_count = 0;
	va_start(params, save);
	if (save)
		check_save_signs(save, params, &c_count);
	va_end(params);
	return (c_count);
}
