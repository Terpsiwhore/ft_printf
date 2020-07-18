
#ifndef FT_CORE_H
#define FT_CORE_H

# include <stdbool.h>

void 	ft_write_c(va_list arg);

void 	ft_write_s(va_list arg);

void 	ft_write_p(va_list arg);

void 	ft_write_di(va_list arg);

void 	ft_write_u(va_list arg);

void 	ft_write_x(va_list arg, bool is_upper);

#endif
