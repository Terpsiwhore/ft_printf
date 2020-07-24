/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:10:33 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/23 09:10:36 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# define FLAG_MINUS		(0b00000001u)
# define FLAG_ZERO 		(0b00000010u)

# define STR_NULL		("(null)")
# define STR_HEX_PREFIX	("0x")

# include <stdarg.h>
# include <unistd.h>

typedef struct		s_format_fields
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
	int				length;
}					t_format_fields;

t_format_fields		*ft_parser(const char *str, va_list *arg);
int					ft_parse_flags(const char *str, t_format_fields *format);
int					ft_parse_width(const char *str, t_format_fields *format,
									va_list *arg);
int					ft_parse_precision(const char *str, t_format_fields *format,
									va_list *arg);
int					ft_parse_type(const char *str, t_format_fields *format);

#endif
