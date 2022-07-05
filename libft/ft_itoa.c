/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:31:47 by mkhalil           #+#    #+#             */
/*   Updated: 2022/06/28 16:55:47 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		count++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	getnbr(char *num, int n, int i)
{
	int	test;

	test = 1000000000;
	if (n == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return ;
	}
	while (n / test <= 0)
		test /= 10;
	while (test > 0)
	{
		num[i] = n / test + '0';
		i++;
		n = n % test;
		test /= 10;
	}
	num[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	num = (char *) malloc (sizeof(char) * (count_digits(n) + 1));
	if (!num)
		return (NULL);
	i = 0;
	if (n == -2147483648)
	{
		num[0] = '-';
		num[1] = '2';
		n = 147483648;
		i = 2;
	}
	else if (n < 0)
	{
		num[0] = '-';
		n = -n;
		i = 1;
	}
	getnbr(num, n, i);
	return (num);
}
