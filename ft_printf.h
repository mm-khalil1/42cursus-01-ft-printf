#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_putnbr_base(size_t nbr, size_t base, int flag);
int	count_digits_u(size_t nbr, size_t base);
int	count_digits_i(int nbr, size_t base);
//int	count_digits(int n, size_t base, int flag);
//char	*ptr_to_hex(uintptr_t address);

#endif
