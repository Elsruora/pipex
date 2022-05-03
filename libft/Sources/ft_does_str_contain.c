/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_does_str_contain.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:58:10 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/10 19:08:55 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_does_str_contain(char *str, char *strc)
{
	unsigned int	i;
	unsigned int	j;
	char			*isin;
	int				res;

	i = -1;
	isin = (char *)malloc(sizeof(*strc) * ft_strlen(strc) + 1);
	if (!isin)
		return (0);
	while (str[++i])
	{
		j = 0;
		while (strc[j])
		{
			if (str[i] == strc[j])
				isin[j] = strc[j];
			j++;
		}
	}
	res = ft_strncmp(isin, strc, ft_strlen(strc));
	free(isin);
	return (res);
}
