/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:47:52 by mkhalil           #+#    #+#             */
/*   Updated: 2022/07/09 18:47:52 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_putnbr_base(size_t nbr, size_t base, int flag);
int		count_digits_u(size_t nbr, size_t base);
int		count_digits_i(int nbr, size_t base);
int		print_c(int c);
int		print_s(char *str);
int		print_i(int nbr);
int		print_u_x(unsigned int nbr, int flag);
int		print_p(uintptr_t ptr_address);
int		ft_printf(const char *format, ...);

#endif
