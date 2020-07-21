/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:26:35 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:26:38 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int 	ft_print_type_i(t_format_fields *format, va_list *arg)
{
	int length;
	int i;

	length = 0;
	i = va_arg(*arg, int);
	ft_putnbr_fd(i, 1);

	return (length);
}