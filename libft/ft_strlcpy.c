/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:35:02 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/04 16:35:04 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_size;

	if (!dst || !src)
		return (0);
	src_size = ft_strlen(src);
	if (size != 0)
	{
		if (src_size + 1 < size)
			ft_memcpy(dst, src, src_size + 1);
		else
		{
			ft_memcpy(dst, src, size - 1);
			dst[size - 1] = '\0';
		}
	}
	return (src_size);
}
