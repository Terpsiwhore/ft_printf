/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 08:08:33 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/22 08:08:35 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/ft_parser.h"

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, str);
	res = ft_parse_string(str, arg);
	va_end(arg);
	return (res);
}