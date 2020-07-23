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
	if (format->precision == 0)
		length = 0;
	else
		length = ft_nbrlen_base(u, 10);
	precision = length > format->precision ? length : format->precision;
	if (!(format->flags & FLG_MINU))
	{
		while ((format->width)-- - precision > 0)
		{
			ft_putchar_fd(format->flags & FLG_ZERO && format->precision < 0 ? '0' : ' ', 1);
			++width;
		}
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
		ft_putnbr_fd(u, 1);
	precision = length > format->precision ? length : format->precision;
	if (format->flags & FLG_MINU)
		while ((format->width)-- - precision > 0)
		{
			ft_putchar_fd(' ', 1);
			++width;
		}
	return (length + width);
}
