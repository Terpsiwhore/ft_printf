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

static int		ft_print_minus(long *i, int is_negative)
{
	if (is_negative)
	{
		ft_putchar_fd('-', 1);
		*i *= -1;
	}
	return (is_negative);
}

static int		ft_print_prefix_flags(t_format_fields *format, long *i,
										int is_neg, int prc)
{
	int width;

	width = 0;
	if (!(format->flags & FLG_MINU))
	{
		if (format->flags & FLG_ZERO && format->precision < 0)
		{
			width += ft_print_minus(i, is_neg);
			width += ft_putchar_n_fd('0', format->width - prc - is_neg, 1);
		}
		else
			width += ft_putchar_n_fd(' ', format->width - prc - is_neg, 1);
		if (format->flags & FLG_ZERO && format->precision > 0)
			width += ft_print_minus(i, is_neg);
	}
	if (!(format->flags & FLG_ZERO))
		width += ft_print_minus(i, is_neg);
	return (width);
}

int				ft_print_type_i(t_format_fields *format, va_list *arg)
{
	int		length;
	int		width;
	int		prc;
	int		is_neg;
	long	i;

	width = 0;
	i = va_arg(*arg, int);
	is_neg = i < 0 ? 1 : 0;
	length = (format->precision == 0 && i == 0) ? 0 : ft_nbrlen_base(i, 10);
	prc = length > format->precision ? length : format->precision;
	width += ft_print_prefix_flags(format, &i, is_neg, prc);
	if (format->precision - length > 0)
		width += ft_putchar_n_fd('0', prc - length, 1);
	if (length > 0)
		ft_putnbr_fd(i, 1);
	if (format->flags & FLG_MINU)
		width += ft_putchar_n_fd(' ', format->width - prc - is_neg, 1);
	return (length + width);
}
