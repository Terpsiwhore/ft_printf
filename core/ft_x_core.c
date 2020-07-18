/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:37:49 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/24 11:37:51 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

void 	ft_write_x(va_list arg, bool is_upper)
{
	int	x;

	x = va_arg(arg, int);
	ft_putnbr_base_fd(x, 16, is_upper, 1);
}
