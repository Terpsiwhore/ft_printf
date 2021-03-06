/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:04:56 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 09:04:58 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int		ft_parse_type(const char *str, t_format_fields *format)
{
	if (*str && ft_strchr("cspdiuxX%n", *str))
	{
		format->type = *str;
		++(format->length);
		return (1);
	}
	return (0);
}
