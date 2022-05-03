/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:58:35 by nchabli           #+#    #+#             */
/*   Updated: 2021/12/06 19:14:08 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char	*base)
{
	int	y;
	int	x;

	x = 0;
	while (base[x])
	{
		y = x + 1;
		if (base[x] == '+' || base[x] == '-' || base[x] == ' ')
			return (0);
		if (base[x] >= 9 && base[x] <= 13)
			return (0);
		while (base[y])
		{
			if (base[x] == base[y])
				return (0);
			y++;
		}
		x++;
	}
	return (x);
}

int	check_nega(char	*str, int n)
{
	int	x;
	int	factor;

	factor = 1;
	x = 0;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			factor *= -1;
		x++;
	}
	if (n == 1)
		return (x);
	else
		return (factor);
}

int	check_cara(char c, char	*base)
{
	int	x;

	x = 0;
	while (base[x])
	{
		if (base[x] == c)
			return (1);
		x++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	leng_base;
	int	nbr;
	int	x;
	int	factor;
	int	n;

	nbr = 0;
	factor = check_nega(str, 2);
	leng_base = check_base(base);
	if (leng_base <= 1)
		return (0);
	x = check_nega(str, 1);
	while (check_cara(str[x], base) && str[x])
	{
		n = 0;
		while (str[x] != base[n])
			n++;
		nbr = nbr * leng_base + n;
		x++;
	}
	return (nbr * factor);
}
