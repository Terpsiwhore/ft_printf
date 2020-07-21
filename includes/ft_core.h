
#ifndef FT_CORE_H
#define FT_CORE_H

# include "ft_parser.h"
# include <stdbool.h>

int 	ft_print_type_c(t_format_fields *format, va_list *arg);
int 	ft_print_type_s(t_format_fields *format, va_list *arg);
int 	ft_print_type_p(t_format_fields *format, va_list *arg);
int 	ft_print_type_i(t_format_fields *format, va_list *arg);
int 	ft_print_type_u(t_format_fields *format, va_list *arg);
int 	ft_print_type_x(t_format_fields *format, va_list *arg, bool is_upper);


#endif
