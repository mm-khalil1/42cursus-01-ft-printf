/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:35:51 by mkhalil           #+#    #+#             */
/*   Updated: 2022/06/28 16:40:57 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len2;

	if (*s2 == 0 || s2 == 0)
		return ((char *)s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	while (s1[i] != 0 && i < n)
	{
		j = 0;
		while (s1[i] && s2[j] && s1[i + j] == s2[j] && i + j < n)
			j++;
		if (j == len2)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
