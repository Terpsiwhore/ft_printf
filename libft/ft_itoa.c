/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 08:08:24 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/08 08:08:26 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nlen(int n)
{
	int n_len;

	n_len = 1;
	while (n /= 10)
		n_len++;
	return (n_len);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		is_neg;
	int		n_len;

	is_neg = (n < 0) ? 1 : 0;
	n *= (is_neg) ? 1 : -1;
	n_len = get_nlen(n) + is_neg;
	if ((res = malloc(n_len + 1)))
	{
		res[n_len] = '\0';
		if (is_neg)
			res[0] = '-';
		while (n_len > is_neg)
		{
			res[n_len - 1] = (char)(n % 10 * (-1) + '0');
			n /= 10;
			n_len--;
		}
	}
	return (res);
}
