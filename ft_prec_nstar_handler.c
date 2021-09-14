/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_nstar_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:02:37 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 19:13:46 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_nstar_handler(const char *format, int *i, va_list args)
{
	int a;

	a = *i;
	while (format[a] == '-' || format[a] == '.' || (format[a] >= '0' &&
	format[a] <= '9'))
		a++;
	while (format[*i] == '0')
		++*i;
	if (format[a] == 'd' || format[a] == 'i')
		ft_prec_digital_handler(format, i, va_arg(args, int));
	if (format[a] == 'u')
		ft_prec_int_u(format, i, va_arg(args, unsigned int));
	if (format[a] == 's' && format[a - 1] != 's')
		ft_prec_string(format, i, va_arg(args, char *));
}
