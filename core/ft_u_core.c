/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 09:21:21 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/24 09:21:23 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

void 	ft_write_u(va_list arg)
{
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	ft_putnbr_fd(u, 1);
}