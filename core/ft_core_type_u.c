/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:28:42 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:28:43 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_print_type_u(t_format_fields *format, va_list *arg)
{
	int				length;
	int				width;
	int				precision;
	unsigned int	u;

	width = 0;
	u = va_arg(*arg, unsigned int);
	length = (!(format->precision) && !u) ? 0 : ft_nbrlen_base(u, 10);
	precision = length > format->precision ? length : format->precision;
	if (!(format->flags & FLAG_MINUS))
	{
		if (format->flags & FLAG_ZERO && format->precision < 0)
			width += ft_putcharn_fd('0', format->width - precision, STDOUT);
		else
			width += ft_putcharn_fd(' ', format->width - precision, STDOUT);
	}
	if (format->precision - length > 0)
		width += ft_putcharn_fd('0', precision - length, STDOUT);
	if (length > 0)
		ft_putnbr_fd(u, STDOUT);
	if (format->flags & FLAG_MINUS)
		width += ft_putcharn_fd(' ', format->width - precision, STDOUT);
	return (length + width);
}
