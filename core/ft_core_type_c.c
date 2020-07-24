/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:11:07 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:11:08 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_print_type_c(t_format_fields *format, va_list *arg)
{
	int		length;
	char	c;

	c = va_arg(*arg, int);
	length = format->width > 0 ? (int)format->width : 1;
	if (!(format->flags & FLAG_MINUS))
		ft_putcharn_fd(' ', format->width - 1, STDOUT);
	ft_putchar_fd(c, STDOUT);
	if (format->flags & FLAG_MINUS)
		ft_putcharn_fd(' ', format->width - 1, STDOUT);
	return (length);
}
