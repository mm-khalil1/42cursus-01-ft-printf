/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:08:27 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/06 11:08:27 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int n, int fd, unsigned int base)
{
	char	*ref;

	ref = "0123456789abcdef";
	if (fd < 0)
		return ;
	if (n < base)
		ft_putchar_fd(ref[n], fd);
	else
	{
		ft_putunbr_fd(n / base, fd);
		ft_putunbr_fd(n % base, fd);
	}
}
