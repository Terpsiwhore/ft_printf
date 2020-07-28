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

int				ft_print_type_i(t_format_fields *f, va_list *arg)
{
	int		length;
	int		width;
	int		prc;
	bool	is_sign;
	long	i;

	width = 0;
	i = va_arg(*arg, int);
	is_sign = i < 0 || f->flags & FLAG_PLUS || f->flags & FLAG_SPACE;
	length = (!(f->precision) && !i) ? 0 : ft_nbrlen_base(i, 10);
	prc = length > f->precision ? length : f->precision;
	f->flags &= f->flags & FLAG_ZERO && f->precision > 0 ? (~FLAG_ZERO) : ~0u;
	if (!(f->flags & FLAG_MINUS))
	{
		f->flags & FLAG_ZERO ? ft_print_sign(f, i) : 0;
		width += ft_putcharn_fd(f->flags & FLAG_ZERO ? '0' : ' ',
				f->width - prc - is_sign, STDOUT);
	}
	!(f->flags & FLAG_ZERO) ? ft_print_sign(f, i) : 0;
	f->precision - length > 0 ? width += ft_putcharn_fd('0',
			prc - length, STDOUT) : 0;
	length > 0 ? ft_putnbr_fd(i * (1 - 2 * is_sign), STDOUT) : 0;
	f->flags & FLAG_MINUS ? width += ft_putcharn_fd(' ',
			f->width - prc - is_sign, STDOUT) : 0;
	return (length + width + is_sign);
}
