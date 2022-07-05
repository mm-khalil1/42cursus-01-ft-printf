/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:34:54 by mkhalil           #+#    #+#             */
/*   Updated: 2022/06/27 18:16:59 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dsize;
	size_t	i;

	dsize = ft_strlen(dest);
	if (n <= dsize)
		return (ft_strlen(src) + n);
	i = 0;
	while (src[i] && i < (n - dsize - 1))
	{
		dest[dsize + i] = src[i];
		i++;
	}
	dest[dsize + i] = 0;
	return (dsize + ft_strlen(src));
}
