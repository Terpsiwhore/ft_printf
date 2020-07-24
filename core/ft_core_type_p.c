/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:23:30 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:23:33 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int			ft_print_type_p(t_format_fields *format, va_list *arg)
{
	int		length;
	int		width;
	int		prfx_len;
	size_t	p;

	p = va_arg(*arg, size_t);
	width = 0;
	prfx_len = ft_strlen(STR_HEX_PREFIX);
	length = ft_nbrlen_base(p, 16) + prfx_len;
	if (!(format->flags & FLAG_MINUS))
		width += ft_putchar_n_fd(' ', format->width - length, 1);
	ft_putstr_fd(STR_HEX_PREFIX, 1);
	if (format->precision - length + prfx_len > 0)
		width += ft_putchar_n_fd('0', format->precision - length + prfx_len, 1);
	ft_putnbr_base_fd(p, 16, 0, 1);
	if (format->flags & FLAG_MINUS)
		width += ft_putchar_n_fd(' ', format->width - length, 1);
	return (length + width);
}
