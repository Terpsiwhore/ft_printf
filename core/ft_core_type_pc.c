/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_pc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:43:19 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:43:21 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int ft_print_type_pc(t_format_fields *format)
{
	int length;

	length = format->width > 0 ? (int)format->width : 1;
	if (!(format->flags & FLAG_MINUS))
	{
		if (format->flags & FLAG_ZERO)
			ft_putcharn_fd('0', format->width - 1, STDOUT);
		else
			ft_putcharn_fd(' ', format->width - 1, STDOUT);
	}
	ft_putchar_fd('%', STDOUT);
	if (format->flags & FLAG_MINUS)
		ft_putcharn_fd(' ', format->width - 1, STDOUT);
	return (length);
}
