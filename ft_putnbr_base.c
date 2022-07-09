/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:08:27 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/08 11:44:12 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u_x(size_t nbr, size_t base, int flag)
{
	char	*ref;

	ref = "0123456789abcdef";
	if (nbr < base)
	{
		if (flag == 'X' && base == 16)
			ft_putchar_fd(ft_toupper(ref[nbr]), 1);
		else	
			ft_putchar_fd(ref[nbr], 1);
	}
	else
	{
		ft_putnbr_u_x(nbr / base, base, flag);
		ft_putnbr_u_x(nbr % base, base, flag);
	}
}
