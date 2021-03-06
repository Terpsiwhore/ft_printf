/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:12:12 by kcorazon          #+#    #+#             */
/*   Updated: 2020/07/23 09:12:14 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CORE_H
# define FT_CORE_H

# include "ft_parser.h"
# include <stdbool.h>
# include <stdlib.h>

int		ft_core(t_format_fields *format, va_list *arg, int printf_length);
int		ft_print_type_c(t_format_fields *format, va_list *arg);
int		ft_print_type_s(t_format_fields *format, va_list *arg);
int		ft_print_type_p(t_format_fields *format, va_list *arg);
int		ft_print_type_i(t_format_fields *format, va_list *arg);
int		ft_print_type_u(t_format_fields *format, va_list *arg);
int		ft_print_type_x(t_format_fields *format, va_list *arg, bool is_upper);
int		ft_print_type_pc(t_format_fields *format, va_list *arg);
int		ft_set_pointer_n(va_list *arg, int printf_length);

#endif
