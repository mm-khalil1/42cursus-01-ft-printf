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

static int	count_digits(unsigned int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n > 15 || n < -15)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*dec_to_hex(unsigned int num, int flag)
{
	char	* base;
	char	* hex;
	int		count;

	base = "0123456789ABCDEF";
	count = count_digits(num);
	hex = malloc (sizeof(char) * (count + 1));
	if (!hex)
		return (NULL);
	hex[count] = '\0';
	count--;
	while (count > 0)
	{
		hex[count] = base[num % 16];
		num /= 16;
		count--;
	}
	if (flag == 'x')
		while (hex[++count])
			if (ft_isalpha(hex[count]))
				hex[count] = ft_tolower(hex[count]);
	return (hex);
}

int	ft_printf(char *format, ...)
{
	va_list ap;
	char	*hex;
	
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1);
		else
		{
			*format++;
			if (*format == '%')
				ft_putchar_fd('%', 1);
			else if (*format == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (*format == 'u')
				ft_putnbr_fd(va_arg(ap, unsigned int), 1);
			else if (*format == 'x' || *format == 'X')
			{
				hex = dec_to_hex(va_arg(ap, unsigned int), *format);
				ft_putstr_fd(hex, 1);
				free(hex);
			}
		}
		format++;
	}
	va_end(ap);
}

#include <stdio.h>

int main()
{
	printf("Hello");
	ft_printf("Hello");
}