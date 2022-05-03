/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_have_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:48:07 by nchabli           #+#    #+#             */
/*   Updated: 2022/04/20 15:55:55 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

int	ft_have_print(char *str)
{
	int	i;
	int	contain_print;

	i = -1;
	contain_print = 0;
	while (str[++i])
	{
		if (ft_isprint(str[i]) && str[i] != 32)
			contain_print++;
	}
	if (contain_print > 0)
		return (0);
	else
		return (1);
}
