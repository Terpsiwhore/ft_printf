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
	length = (!(format->precision) && !u) ? 0 : ft_nbrlen_base(u, BASE_10);
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
		ft_putnbr_fd(u, 1);
	if (format->flags & FLG_MINU)
		width += ft_putchar_n_fd(' ', format->width - precision, 1);
	return (length + width);
}
