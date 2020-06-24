/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:37:03 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/24 08:37:04 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

void 	ft_write_s(va_list arg)
{
	char 	*s;

	s = va_arg(arg, char *);
	ft_putstr_fd(s, 1);
}