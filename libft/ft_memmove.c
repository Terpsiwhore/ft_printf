/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:57:49 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/04 13:57:51 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*head;

	head = (char *)dest;
	if (dest == src)
		return (dest);
	else if (dest < src)
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(unsigned char *)--dest = *(unsigned char *)--src;
	}
	return (head);
}
