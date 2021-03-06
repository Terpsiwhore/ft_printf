/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:52:27 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 08:52:30 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_parse_precision(const char *str, t_format_fields *format,
							va_list *arg)
{
	int	length;

	length = 0;
	if (*str == '.')
	{
		++str;
		if (*str == '*')
		{
			format->precision = va_arg(*arg, int);
			++length;
		}
		else if (ft_isdigit(*str))
		{
			format->precision = ft_atoi(str);
			while (ft_isdigit(*(str + length)))
				++length;
		}
		++length;
	}
	else
		format->precision = -1;
	format->length += length;
	return (length);
}
