#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_putnbr_u_x(unsigned int n, unsigned int base, int flag);
int	count_digits(int n, unsigned int base, int flag);
int		count_digits_u(unsigned int n, unsigned int base);
int		count_digits_i(int n, unsigned int base);
char	*ptr_to_hex(uintptr_t address);

#endif
