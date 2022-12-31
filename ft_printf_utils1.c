/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:31:29 by mkhalil           #+#    #+#             */
/*   Updated: 2022/12/31 19:13:37 by mkhalil          ###   ########.fr       */
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
	ft_putstr_fd("0x", 1);
	if (ptr_address == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	ft_putnbr_base(ptr_address, 16, 'x');
	return (2 + count_digits_u(ptr_address, 16));
}
