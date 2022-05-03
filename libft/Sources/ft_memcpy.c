/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:24:36 by nchabli           #+#    #+#             */
/*   Updated: 2021/11/08 08:47:04 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memcpy(void *destination, const void *source, size_t size )
{
	unsigned char			*dest;
	const unsigned char		*src;

	if (!destination && !source)
		return (NULL);
	src = (unsigned char *) source;
	dest = (unsigned char *) destination;
	while (size-- > 0)
		*(dest++) = *(src++);
	return (destination);
}
