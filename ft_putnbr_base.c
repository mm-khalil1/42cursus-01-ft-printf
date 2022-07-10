/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:48:04 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/09 18:48:04 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(size_t nbr, size_t base, int flag)
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
		ft_putnbr_base(nbr / base, base, flag);
		ft_putnbr_base(nbr % base, base, flag);
	}
}
