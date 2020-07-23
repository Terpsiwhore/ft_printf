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
	length = (!(format->precision) && !x) ? 0 : ft_nbrlen_base(x, BASE_16);
	precision = length > format->precision ? length : format->precision;
	if (!(format->flags & FLG_MINU))
	{
		if (format->flags & FLG_ZERO && format->precision < 0)
			width += ft_putchar_n_fd('0', format->width - precision, 1);
		else
			width += ft_putchar_n_fd(' ', format->width - precision, 1);
	}
	if (format->precision - length > 0)
		width += ft_putchar_n_fd('0', precision - length, 1);
	if (length > 0)
		ft_putnbr_base_fd(x, BASE_16, is_upper, 1);
	if (format->flags & FLG_MINU)
		width += ft_putchar_n_fd(' ', format->width - precision, 1);
	return (length + width);
}
