/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:28:06 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 08:28:09 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_parse_width(const char *str, t_format_fields *format, va_list *arg)
{
	int		length;

	length = 0;
	if (*str == '*')
	{
		format->width = va_arg(*arg, int);
		if (format->width < 0)
		{
			format->flags |= FLAG_MINUS;
			if ((format->flags & FLAG_ZERO) && (format->flags & FLAG_MINUS))
				format->flags &= (~FLAG_ZERO);
			format->width *= -1;
		}
		++length;
	}
	else if (ft_isdigit(*str))
	{
		format->width = ft_atoi(str);
		while (ft_isdigit(*(str + length)))
			++length;
	}
	format->length += length;
	return (length);
}
