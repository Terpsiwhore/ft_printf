/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:32:40 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/08 10:32:41 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long long n, int base, bool is_upper, int fd)
{
	int reg;

	reg = is_upper ? 0 : 'a' - 'A';
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n *= -1;
	if (n <= -base)
		ft_putnbr_base_fd(n / base * (-1), base, is_upper, fd);
	if ((n % base * (-1) < 10))
		ft_putchar_fd((char)(n % base * (-1) + '0'), fd);
	else
		ft_putchar_fd((char)(n % base * (-1) - 10 + 'A' + reg), fd);
}
