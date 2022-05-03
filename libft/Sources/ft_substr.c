/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:57:43 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/22 19:31:14 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_loop(const char *s, size_t len, char *str, unsigned int start)
{
	size_t	j;

	j = 0;
	while (s[start] && j < len)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || ft_strlen(s) <= start)
	{
		str = ft_strdup("\0");
		return (str);
	}
	if (len < ft_strlen(s))
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
	}
	else
	{
		str = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!str)
			return (NULL);
	}
	return (ft_loop(s, len, str, start));
}
