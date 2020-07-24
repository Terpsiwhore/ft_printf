/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:18:39 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:18:42 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_print_type_s(t_format_fields *format, va_list *arg)
{
	int		length;
	int		width;
	char	*s;

	s = va_arg(*arg, char *);
	width = 0;
	if (s == NULL)
		s = STR_NULL;
	length = ft_strlen(s);
	if (format->precision >= 0 && length > format->precision)
		length = format->precision;
	if (!(format->flags & FLAG_MINUS))
		width += ft_putchar_n_fd(' ', format->width - length, 1);
	write(1, s, length);
	if (format->flags & FLAG_MINUS)
		width += ft_putchar_n_fd(' ', format->width - length, 1);
	return (length + width);
}
