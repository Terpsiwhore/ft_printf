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

#include "ft_printf.h"
#include "ft_parser.h"

static int 	ft_print_string_to_percent(const char *str)
{
	int length;

	length = 0;
	while (str[length] && str[length] != '%')
		++length;
	write(1, str, length);
	return (length);
}

int			ft_printf(const char *str, ...)
{
	va_list			arg;
	t_format_fields *format;
	int				length;

	va_start(arg, str);
	length = 0;
	while (*str)
	{
		length = ft_print_string_to_percent(str);
		str += length;
		if (*str == '%')
		{
			++str;
			if ((format = ft_parser(str, &arg)))
			{
				str += format->length;
			}
		}
	}
	va_end(arg);
	return (length);
}