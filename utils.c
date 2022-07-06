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

int	count_digits_u(unsigned int n, unsigned int base)
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

int	count_digits_i(int n, unsigned int base)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (1 + count_digits_u(-n, base)); //plus 1 for the minus
	return (count_digits_u(n, base));
}

char	*dec_to_hex(unsigned int num, int flag)
{
	char	* base;
	char	* hex;
	int		count;

	base = "0123456789abcdef";
	count = count_digits_u(num, 16);
	hex = malloc (sizeof(char) * (count + 1));
	if (!hex)
		return (NULL);
	hex[count] = '\0';
	while (--count >= 0)
	{
		hex[count] = base[num % 16];
		num /= 16;
	}
	if (flag == 'X')
		while (hex[++count])
			if (ft_isalpha(hex[count]))
				hex[count] = ft_toupper(hex[count]);
	return (hex);
}

char	*ptr_to_hex(uintptr_t address)
{
	char		* base;
	char		* hex;
	int			count;
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
