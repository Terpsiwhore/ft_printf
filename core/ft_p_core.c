/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:44:19 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/24 08:44:20 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

void 	ft_write_p(va_list arg)
{
	size_t	p;

	p = va_arg(arg, size_t);
	ft_putnbr_fd(p, 16, 1);
}
