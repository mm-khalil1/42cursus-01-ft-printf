/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:01:35 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/08 11:39:49 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	print_s(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	print_i(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (count_digits_i(nbr, 10));
}

static int	print_u_x(unsigned int nbr, int flag)
{
	if (flag == 'u')
	{
		ft_putnbr_u_x(nbr, 10, flag);
		return (count_digits_u(nbr, 10, flag));
	}
	else
	{
		ft_putnbr_u_x(nbr, 16, flag);
		return (count_digits_u(nbr, 16, flag));
	}
}

static int	print_p(uintptr_t ptr_add)
{
	if (ptr_add == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_u_x(ptr_add, 16, 'x');
	return (2 + count_digits_u(ptr_add, 16));
}

static int	print_all(va_list ap, const char *format)
{
	int	num;

	num = 0;
	if (*format == '%')
		num = print_c('%');
	else if (*format == 'c')
		num = print_c(va_arg(ap, int));
	else if (*format == 's')
		num = print_s(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		num = print_i(va_arg(ap, int));
	else if (*format == 'u' || *format == 'x' || *format == 'X')
		num = print_u_x(va_arg(ap, unsigned int), *format);
	else if (*format == 'p')
		num = print_p(va_arg(ap, uintptr_t));
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		num_chars;
	
	num_chars = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			num_chars += print_all(ap, ++format);
		else 
		{
			ft_putchar_fd(*format, 1);
			num_chars++;
		}
		format++;
	}
	va_end(ap);
	return (num_chars);
}
