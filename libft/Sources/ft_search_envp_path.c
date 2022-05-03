/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_envp_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:46:38 by nchabli           #+#    #+#             */
/*   Updated: 2022/04/20 12:02:38 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_search_envp_path(char **envp)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	k = 0;
	i = -1;
	j = 0;
	str = "PATH=";
	while (envp[++i])
	{
		while (envp[i][j])
		{
			while (envp[i][k] == str[k])
				k++;
			if (!str[k])
				return (envp[i]);
			j++;
		}
	}
	return (NULL);
}
