/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:31:29 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/10 21:35:05 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_s(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_i(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (count_digits_i(nbr, 10));
}

int	print_u_x(unsigned int nbr, int flag)
{
	if (flag == 'u')
	{
		ft_putnbr_base(nbr, 10, flag);
		return (count_digits_u(nbr, 10));
	}
	else
	{
		ft_putnbr_base(nbr, 16, flag);
		return (count_digits_u(nbr, 16));
	}
}

int	print_p(uintptr_t ptr_address)
{
	if (ptr_address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(ptr_address, 16, 'x');
	return (2 + count_digits_u(ptr_address, 16));
}
