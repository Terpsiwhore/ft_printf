/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 08:08:33 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/22 08:08:35 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_core.h"

int			ft_printf(const char *str, ...)
{
	va_list			arg;
	t_format_fields *format;
	int				length;

	va_start(arg, str);
	length = 0;
	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar_fd(*str++, 1);
			++length;
		}
		if (*str == '%')
		{
			++str;
			if ((format = ft_parser(str, &arg)))
			{
				str += format->length;
				length += ft_core(format, &arg);
			}
		}
	}
	va_end(arg);
	return (length);
}
