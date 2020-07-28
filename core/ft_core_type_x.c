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

static int	ft_print_prefix_flags(t_format_fields *format, int prec, int hash,
									bool is_upper)
{
	int	width;

	width = 0;
	if (!(format->flags & FLAG_MINUS))
	{
		if (format->flags & FLAG_ZERO && format->precision < 0)
		{
			write(STDOUT, is_upper ? STR_UP_HEX_PREFIX : STR_HEX_PREFIX, hash);
			width += ft_putcharn_fd('0', format->width - prec - hash, STDOUT);
			hash = 0;
		}
		else
			width += ft_putcharn_fd(' ', format->width - prec - hash, STDOUT);
	}
	write(STDOUT, is_upper ? STR_UP_HEX_PREFIX : STR_HEX_PREFIX, hash);
	return (width);
}

int			ft_print_type_x(t_format_fields *format, va_list *arg,
									bool is_upper)
{
	int				length;
	int				width;
	int				prec;
	int				hash;
	unsigned int	x;

	width = 0;
	x = va_arg(*arg, unsigned int);
	length = (!(format->precision) && !x) ? 0 : ft_nbrlen_base(x, 16);
	prec = length > format->precision ? length : format->precision;
	hash = format->flags & FLAG_HASH && x ? (int)ft_strlen(STR_HEX_PREFIX) : 0;
	width += ft_print_prefix_flags(format, prec, hash, is_upper);
	width += ft_putcharn_fd('0', prec - length, STDOUT);
	if (length > 0)
		ft_putnbr_base_fd(x, 16, is_upper, 1);
	if (format->flags & FLAG_MINUS)
		width += ft_putcharn_fd(' ', format->width - prec - hash, STDOUT);
	return (length + width + hash);
}
