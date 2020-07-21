/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:39:56 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/19 11:39:58 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

t_format_fields *ft_parser(const char *str, va_list *arg)
{
	t_format_fields *format;

	if ((format = malloc(sizeof(t_format_fields))))
	{
		format->length = 0;
		str += ft_parse_flags(str, format);
		str += ft_parse_width(str, format, arg);
		str += ft_parse_precision(str, format, arg);
		if (ft_parse_type(str, format) == 0)
		{
			free(format);
			return (NULL);
		}
	}
	return (format);
}