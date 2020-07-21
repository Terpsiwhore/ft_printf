
#ifndef FT_PARSER_H
# define FT_PARSER_H

# define FLAG_MINU 0b00000001u
# define FLAG_ZERO 0b00000010u

# include <stdarg.h>
# include <unistd.h>

typedef struct		s_format_fields
{
	unsigned char	flags;
	unsigned int	width;
	int				precision;
	char			type;
	unsigned int	length;
}					t_format_fields;

t_format_fields		*ft_parser(const char *str, va_list *arg);
int					ft_parse_flags(const char *str, t_format_fields *format);
int 				ft_parse_width(const char *str, t_format_fields *format, va_list *arg);
int 				ft_parse_precision(const char *str, t_format_fields *format, va_list *arg);
int					ft_parse_type(const char *str, t_format_fields *format);

#endif