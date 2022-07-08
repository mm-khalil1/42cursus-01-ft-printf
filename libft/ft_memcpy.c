/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:32:39 by mkhalil           #+#    #+#             */
/*   Updated: 2022/06/28 16:28:20 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	pd = (unsigned char *) dest;
	ps = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return ((void *)pd);
}
