#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_putunbr_fd(unsigned int n, int fd);
int		count_digits_u(unsigned int n, unsigned int base);
int		count_digits_i(int n, unsigned int base);
char	*dec_to_hex(unsigned int num, int flag);
char	*ptr_to_hex(uintptr_t address);

#endif
