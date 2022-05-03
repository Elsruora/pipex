/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:37:53 by nchabli           #+#    #+#             */
/*   Updated: 2022/03/10 18:00:36 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*p;

	p = (void *) malloc (nb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nb * size);
	return (p);
}
