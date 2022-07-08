/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:30:40 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/06 12:22:35 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_u(size_t n, size_t base)
{
	int	count;

	count = 1;
	while (n > (base - 1))
	{
		n /= base;
		count++;
	}
	return (count);
}

int	count_digits_i(int n, size_t base)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (1 + count_digits_u(-n, base)); //plus 1 for the minus
	return (count_digits_u(n, base));
}

int	count_digits(int n, size_t base, int flag)
{
	int	count;
	size_t	nb;
	
	count = 1;
	if (flag == 'i')
	{
		if (n == -2147483648)
			return (11);
		if (n < 0)
		{
			count++;
			nb = -n;
		}
	}
	if (flag == 'u')
		nb = (size_t) n;
	while (nb > (base - 1))
	{
		nb /= base;
		count++;
	}
	return (count);
}

char	*ptr_to_hex(uintptr_t address)
{
	char		* base;
	char		* hex;
	int		count;
	uintptr_t	temp_add;

	base = "0123456789abcdef";
	count = 1;
	temp_add = address;
	while (temp_add > 15)
	{
		temp_add /= 16;
		count++;
	}
	hex = malloc (sizeof(char) * (count + 1));
	if (!hex)
		return (NULL);
	hex[count] = '\0';
	while (--count >= 0)
	{
		hex[count] = base[address % 16];
		address /= 16;
	}
	return (hex);
}
