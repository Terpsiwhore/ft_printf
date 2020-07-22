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

int 	ft_print_type_s(t_format_fields *format, va_list *arg)
{
	int		length;
	char 	*s;

	s = va_arg(*arg, char *);
	if (s == NULL)
		s = STR_NULL;
	length = ft_strlen(s);
	if (format->precision >= 0 && length > format->precision)
		length = format->precision;
	if (format->width == 0)
		write(1, s, length);
	else
	{
		if (!(format->flags & FLG_MINU))
			while ((format->width)-- - length > 0)
				ft_putchar_fd(' ', 1);
		write(1, s, length);
		if (format->flags & FLG_MINU)
			while ((format->width)-- - length > 0)
				ft_putchar_fd(' ', 1);
	}
	return (length);
}