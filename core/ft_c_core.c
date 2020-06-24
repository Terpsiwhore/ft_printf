/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:26:42 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/24 08:26:43 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

void 	ft_write_c(va_list arg)
{
	char 	c;

	c = va_arg(arg, int);
	ft_putchar_fd(c, 1);
}
