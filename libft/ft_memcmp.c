/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:54:52 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/04 14:54:53 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_d;
	unsigned char *s2_d;

	s1_d = (unsigned char *)s1;
	s2_d = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_d != *s2_d)
			return (*s1_d - *s2_d);
		s1_d++;
		s2_d++;
	}
	return (0);
}
