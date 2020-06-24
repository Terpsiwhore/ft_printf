/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:14:46 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/05 10:14:49 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *s_ptr;

	s_ptr = NULL;
	while (*s)
	{
		if (*s == c)
			s_ptr = s;
		++s;
	}
	return ((c == '\0') ? (char *)s : (char *)s_ptr);
}
