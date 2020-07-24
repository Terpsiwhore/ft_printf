/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:08:43 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 08:08:44 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_parse_flags(const char *str, t_format_fields *format)
{
	int length;

	length = 0;
	while (str[length])
	{
		if (str[length] == '-')
			format->flags |= FLAG_MINUS;
		else if (str[length] == '0')
			format->flags |= FLAG_ZERO;
		else
			break ;
		++length;
	}
	if ((format->flags & FLAG_ZERO) && (format->flags & FLAG_MINUS))
		format->flags &= (~FLAG_ZERO);
	format->length += length;
	return (length);
}
