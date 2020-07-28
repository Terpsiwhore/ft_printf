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

int		ft_core(t_format_fields *format, va_list *arg, int printf_length)
{
	int	length;

	length = 0;
	if (format->type == 'c')
		length = ft_print_type_c(format, arg);
	else if (format->type == 's')
		length = ft_print_type_s(format, arg);
	else if (format->type == 'p')
		length = ft_print_type_p(format, arg);
	else if (format->type == 'd' || format->type == 'i')
		length = ft_print_type_i(format, arg);
	else if (format->type == 'u')
		length = ft_print_type_u(format, arg);
	else if (format->type == 'x' || format->type == 'X')
		length = ft_print_type_x(format, arg, format->type == 'X');
	else if (format->type == '%')
		length = ft_print_type_pc(format, arg);
	else if (format->type == 'n')
		length = ft_set_pointer_n(arg, printf_length);
	free(format);
	return (length);
}
