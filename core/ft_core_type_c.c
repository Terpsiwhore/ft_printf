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

int 	ft_print_type_c(t_format_fields *format, va_list *arg)
{
	int		length;
	char 	c;

	length = 1;
	c = va_arg(*arg, int);
	if (format->width == 0)
		ft_putchar_fd(c, 1);
	else
	{
		length = format->width;
		if (!(format->flags & FLG_MINU))
			while ((format->width)-- - 1 > 0)
				ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
		if (format->flags & FLG_MINU)
			while ((format->width)-- - 1 > 0)
				ft_putchar_fd(' ', 1);
	}
	return (length);
}
