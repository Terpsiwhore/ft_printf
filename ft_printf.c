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
#include "ft_parser.h"
#include "ft_core.h"

static void		ft_print_string(const char *str, va_list *arg, int *length)
{
	t_format_fields	*format;

	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar_fd(*str++, STDOUT);
			++(*length);
		}
		if (*str == '%')
		{
			if ((format = ft_parser(++str, arg)))
			{
				str += format->length;
				*length += ft_core(format, arg);
			}
			else
			{
				*length = -1;
				break ;
			}
		}
	}
}

int				ft_printf(const char *str, ...)
{
	va_list	arg;
	int		length;

	length = 0;
	va_start(arg, str);
	ft_print_string(str, &arg, &length);
	va_end(arg);
	return (length);
}
