/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:33:10 by nchabli           #+#    #+#             */
/*   Updated: 2021/12/14 06:02:19 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		check_base(char	*base);
int		check_nega(char	*str, int n);
int		check_cara(char c, char	*base);
int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa_base(int nbr, char	*base);
int		count_it(int nbr, char *base);
int		da_base(char c, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!check_base(base_from) || !check_base(base_to)
		|| ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2)
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}

char	*ft_itoa_base(int nbr, char	*base)
{
	char		*tab;
	long int	nb;
	int			is_min;
	int			i;

	tab = malloc (sizeof(char) * count_it(nbr, base) + 1);
	if (!tab)
		return (NULL);
	nb = nbr;
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
		is_min = 1;
	}
	else
		is_min = 0;
	i = count_it(nbr, base);
	while (--i >= is_min)
	{
		tab[i] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
	}
	tab[(count_it(nbr, base))] = '\0';
	return (tab);
}

int	count_it(int nbr, char *base)
{
	long int	nb;
	int			count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb >= ft_strlen(base))
	{
		nb = nb / ft_strlen(base);
		count++;
	}
	count++;
	return (count);
}

int	da_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (c == base[i])
			return (1);
	}
	return (0);
}
