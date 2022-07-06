/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:01:35 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/05 19:01:58 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	print_s(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

static int	print_i(int n)
{
	ft_putnbr_fd(n, 1);
	return (count_digits_i(n, 10));
}

static int	print_u_x(unsigned int n, int flag)
{
	char	*hex;

	if (flag == 'u')
	{
		ft_putunbr_fd(n, 1);
		return (count_digits_u(n, 10));
	}
	else
	{
		hex = dec_to_hex(n, flag);
		ft_putstr_fd(hex, 1);
		free(hex);
		return (count_digits_u(n, 16));
	}
}

static int	print_p(uintptr_t p)
{
	int		num;
	char	*hex;

	hex = ptr_to_hex(p);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex, 1);
	num = 2 + ft_strlen(hex); //add 2 for "0x"
	free(hex);
	return (num);
}

static int	print_all(va_list ap, const char *format)
{
	int		num;

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
