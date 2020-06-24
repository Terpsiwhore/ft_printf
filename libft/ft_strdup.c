/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:33:04 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/05 21:33:06 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	size_t	len;

	len = ft_strlen(s) + 1;
	if ((dup_str = malloc(len)))
		ft_memcpy(dup_str, s, len);
	return (dup_str);
}
