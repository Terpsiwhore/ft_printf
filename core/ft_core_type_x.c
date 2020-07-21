/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:30:31 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:30:33 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int 	ft_print_type_x(t_format_fields *format, va_list *arg, bool is_upper)
{
	int length;
	int	x;

	length = 0;
	x = va_arg(*arg, int);
	ft_putnbr_base_fd(x, 16, is_upper, 1);
	return (length);
}