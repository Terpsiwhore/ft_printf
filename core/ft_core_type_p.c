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
	int		len;
	int		wdth;
	int		pfx_len;
	size_t	p;

	p = va_arg(*arg, size_t);
	wdth = 0;
	pfx_len = ft_strlen(STR_HEX_PREFIX);
	len = (!(format->precision) && !p) ? 0 : ft_nbrlen_base(p, 16) + pfx_len;
	if (!(format->flags & FLAG_MINUS))
		wdth += ft_putcharn_fd(' ', format->width - len, STDOUT);
	ft_putstr_fd(STR_HEX_PREFIX, STDOUT);
	if (len > 0 && format->precision - len + pfx_len > 0)
		wdth += ft_putcharn_fd('0', format->precision - len + pfx_len, STDOUT);
	if (len > 0)
		ft_putnbr_base_fd(p, 16, 0, STDOUT);
	if (format->flags & FLAG_MINUS)
		wdth += ft_putcharn_fd(' ', format->width - len, 1);
	return (len + wdth);
}
