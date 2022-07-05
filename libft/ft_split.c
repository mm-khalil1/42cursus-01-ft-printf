/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:34:04 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/01 11:08:52 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_chr_ind(const char *s, char c, size_t i)
{
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (-1);
	return (i);
}

static size_t	last_chr_ind(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i - 1);
}

static int	count_words(const char *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		i = next_chr_ind(s, c, i);
		if (i == -1)
			return (count);
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i++] = ft_substr(s, 0, last_chr_ind(s, c) + 1);
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = 0;
	return (split);
}
