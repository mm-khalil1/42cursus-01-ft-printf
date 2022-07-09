/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:48:16 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/09 18:48:16 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_u(size_t nbr, size_t base)
{
	int	count;

	count = 1;
	while (nbr > (base - 1))
	{
		nbr /= base;
		count++;
	}
	return (count);
}

int	count_digits_i(int nbr, size_t base)
{
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
		return (1 + count_digits_u(-nbr, base)); //plus 1 for the minus
	return (count_digits_u(nbr, base));
}
