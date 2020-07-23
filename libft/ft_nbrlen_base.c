/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:56:11 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/22 09:56:13 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen_base(long nbr, unsigned int base)
{
	int length;

	length = 1;
	while (nbr / base)
	{
		nbr /= base;
		++length;
	}
	return (length);
}
