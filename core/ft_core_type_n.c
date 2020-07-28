/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:16:28 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/28 11:16:31 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_set_pointer_n(va_list *arg, int printf_length)
{
	int 	*n;

	n = va_arg(*arg, int *);
	*n = printf_length;
	return (0);
}
