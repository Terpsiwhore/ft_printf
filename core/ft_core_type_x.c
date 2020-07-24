/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:30:31 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:30:33 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_print_type_x(t_format_fields *format, va_list *arg, bool is_upper)
{
	int				length;
	int				width;
	int				precision;
	unsigned int	x;

	width = 0;
	x = va_arg(*arg, unsigned int);
	length = (!(format->precision) && !x) ? 0 : ft_nbrlen_base(x, 16);
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
		ft_putnbr_base_fd(x, 16, is_upper, 1);
	if (format->flags & FLAG_MINUS)
		width += ft_putcharn_fd(' ', format->width - precision, STDOUT);
	return (length + width);
}
