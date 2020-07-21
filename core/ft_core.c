/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:45:13 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:45:14 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core.h"

int 	ft_core(t_format_fields *format, va_list *arg)
{
	int	length;

	if (format->type == 'c')
		length = ft_print_type_c(format, arg);
	if (format->type == 's')
		length = ft_print_type_s(format, arg);
	if (format->type == 'p')
		length = ft_print_type_p(format, arg);
	if (format->type == 'd' || format->type == 'i')
		length = ft_print_type_i(format, arg);
	if (format->type == 'u')
		length = ft_print_type_u(format, arg);
	if (format->type == 'x' || format->type == 'X')
		length = ft_print_type_x(format, arg, format->type == 'X');
	free(format);
	return (length);
}