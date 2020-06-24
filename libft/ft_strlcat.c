/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:10:23 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/05 09:10:26 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dts_size;
	size_t src_size;

	dts_size = 0;
	while (dst[dts_size] && dts_size != size)
		dts_size++;
	src_size = ft_strlen(src);
	if (dts_size == size)
		return (size + src_size);
	else if (src_size < size - dts_size)
		ft_memcpy(dst + dts_size, src, src_size + 1);
	else
		ft_strlcpy(dst + dts_size, src, size - dts_size);
	return (dts_size + src_size);
}
