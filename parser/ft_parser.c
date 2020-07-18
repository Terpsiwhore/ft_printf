/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 08:26:31 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/22 08:26:32 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parser.h"
#include "includes/ft_core.h"

int 	ft_parse_format(const char *str, va_list arg)
{
	int i;

	i = 0;
	if (*str == 'c')
	{
		++i;
		ft_write_c(arg);
	}
	else if (*str == 's')
	{
		++i;
		ft_write_s(arg);
	}
	else if (*str == 'p')
	{
		++i;
		ft_write_p(arg);
	}
	else if (*str == 'd' || *str == 'i')
	{
		++i;
		ft_write_di(arg);
	}
	else if (*str == 'u')
	{
		++i;
		ft_write_u(arg);
	}
	else if (*str == 'X' || *str == 'x')
	{
		++i;
		ft_write_x(arg, (*str == 'X' ? 1 : 0));
	}
	return (i);
}

int 	ft_parse_string(const char *str, va_list arg)
{
	int 	i;
	int 	start;

	i = 0;
	while (str[i])
	{
		start = i;
		if (str[i] == '%')
		{
			++i;
			i += ft_parse_format(str + i, arg);
		}
		else
		{
			while(str[i] && str[i] != '%')
				++i;
			write(1, str+start, i - start);
		}
	}
	return (0);
}