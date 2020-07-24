/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:47:34 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/23 09:47:35 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putcharn_fd(char c, int n, int fd)
{
	char length;

	length = 0;
	while (n-- > 0)
	{
		write(fd, &c, 1);
		++length;
	}
	return (length);
}
