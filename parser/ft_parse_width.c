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

int 	ft_parse_width(const char *str, t_format_fields *format, va_list *arg)
{
	int				length;
	unsigned int	width;

	length = 0;
	width = 0;
	if (*str == '*')
	{
		format->width = va_arg(*arg, int);
		if (format->width < 0)
		{
			format->flags |= FLG_MINU;
			format->width *= -1;
		}
		++length;
	}
	else
	{
		while (ft_isdigit(str[length]))
		{
			width = width * 10 + (str[length] - '0');
			++length;
		}
		format->width = width;
	}
	format->length += length;
	return (length);
}