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
	char *types;

	types = "cspdiuxX%";
	if (*str && ft_strchr(types, *str))
	{
		format->type = *str;
		++(format->length);
		return (1);
	}
	return (0);
}
