/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:28:42 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:28:43 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int 	ft_print_type_u(t_format_fields *format, va_list *arg)
{
	int length;
	unsigned int	u;

	length = 0;
	u = va_arg(*arg, unsigned int);
	ft_putnbr_fd(u, 1);
	return (length);
}
