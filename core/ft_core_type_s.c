/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_type_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:18:39 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/21 11:18:42 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

int 	ft_print_type_s(t_format_fields *format, va_list *arg)
{
	int		length;
	char 	*s;

	length = 0;
	s = va_arg(*arg, char *);
	if (s == NULL)
		s = "(null)";
	ft_putstr_fd(s, 1);

	return (length);
}