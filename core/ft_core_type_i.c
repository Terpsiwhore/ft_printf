/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:26:35 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:26:38 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_print_type_i(t_format_fields *format, va_list *arg)
{
	int		length;
	int		width;
	int		precision;
	int		is_negative;
	long	i;

	width = 0;
	i = va_arg(*arg, int);
	is_negative = i < 0 ? 1 : 0;
	if (format->precision == 0)
		length = 0;
	else
		length = ft_nbrlen_base(i, 10);
	precision = length > format->precision ? length : format->precision;
	if (!(format->flags & FLG_MINU))
	{
		if (is_negative && format->flags & FLG_ZERO && format->precision < 0)
		{
			ft_putchar_fd('-', 1);
			i *= -1;
		}
		while ((format->width)-- - precision - is_negative > 0)
		{
			ft_putchar_fd(format->flags & FLG_ZERO && format->precision < 0 ? '0' : ' ', 1);
			++width;
		}
		if (is_negative && format->flags & FLG_ZERO && format->precision > 0)
		{
			ft_putchar_fd('-', 1);
			i *= -1;
		}
	}
	if (is_negative && !(format->flags & FLG_ZERO))
	{
		ft_putchar_fd('-', 1);
		i *= -1;
	}
	if (format->precision - length > 0)
	{
		precision = format->precision;
		while (precision-- - length > 0)
		{
			ft_putchar_fd('0', 1);
			++width;
		}
	}
	if (length > 0)
		ft_putnbr_fd(i, 1);
	precision = length > format->precision ? length : format->precision;
	if (format->flags & FLG_MINU)
		while ((format->width)-- - precision - is_negative > 0)
		{
			ft_putchar_fd(' ', 1);
			++width;
		}
	return (length + width);
}
