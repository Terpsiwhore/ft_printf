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

static void		ft_print_sign(t_format_fields *format, long i)
{
	if (i < 0)
		ft_putchar_fd('-', STDOUT);
	else if (format->flags & FLAG_PLUS)
		ft_putchar_fd('+', STDOUT);
	else if (format->flags & FLAG_SPACE)
		ft_putchar_fd(' ', STDOUT);
}

static int		ft_print_prefix_flags(t_format_fields *format, bool is_sign,
										long i, int prc)
{
	int		width;

	width = 0;
	if (!(format->flags & FLAG_MINUS))
	{
		if (format->flags & FLAG_ZERO && format->precision < 0)
		{
			ft_print_sign(format, i);
			width += ft_putcharn_fd('0', format->width - prc - is_sign, STDOUT);
		}
		else
			width += ft_putcharn_fd(' ', format->width - prc - is_sign, STDOUT);
		if (format->flags & FLAG_ZERO && format->precision > 0)
			ft_print_sign(format, i);
	}
	if (!(format->flags & FLAG_ZERO))
		ft_print_sign(format, i);
	return (width);
}

int				ft_print_type_i(t_format_fields *format, va_list *arg)
{
	int		length;
	int		width;
	int		prc;
	bool	is_sign;
	long	i;

	width = 0;
	i = va_arg(*arg, int);
	is_sign = i < 0 || format->flags & FLAG_PLUS || format->flags & FLAG_SPACE;
	length = (!(format->precision) && !i) ? 0 : ft_nbrlen_base(i, 10);
	prc = length > format->precision ? length : format->precision;
	width += ft_print_prefix_flags(format, is_sign, i, prc);
	if (format->precision - length > 0)
		width += ft_putcharn_fd('0', prc - length, STDOUT);
	if (i < 0)
	{
		i *= -1;
		is_sign = 1;
	}
	if (length > 0)
		ft_putnbr_fd(i, STDOUT);
	if (format->flags & FLAG_MINUS)
		width += ft_putcharn_fd(' ', format->width - prc - is_sign, STDOUT);
	return (length + width + is_sign);
}
