/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:21:04 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/05 13:21:05 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char c1;
	unsigned char c2;

	while (n-- && (*s1 || *s2))
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
			return (c1 > c2 ? 1 : -1);
	}
	return (0);
}
