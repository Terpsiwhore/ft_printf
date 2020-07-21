/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:23:30 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:23:33 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int 	ft_print_type_p(t_format_fields *format, va_list *arg)
{
	int		length;
	size_t	p;

	length = 0;
	p = va_arg(*arg, size_t);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, 16, 0, 1);

	return (length);
}