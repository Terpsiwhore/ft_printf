/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 09:13:29 by kcorazon          #+#    #+#             */
/*   Updated: 2020/06/24 09:13:30 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"

void 	ft_write_di(va_list arg)
{
	int	i;

	i = va_arg(arg, int);
	ft_putnbr_fd(i, 1);
}