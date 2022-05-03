/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:58:50 by nchabli           #+#    #+#             */
/*   Updated: 2021/11/08 05:20:09 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len )
{
	char	*d_copy;
	char	*s_copy;

	d_copy = (char *)dst;
	s_copy = (char *)src;
	if (dst == src)
		return (dst);
	if (s_copy < d_copy)
	{
		while (len--)
			*(d_copy + len) = *(s_copy + len);
		return (dst);
	}
	while (len--)
		*d_copy++ = *s_copy++;
	return (dst);
}
