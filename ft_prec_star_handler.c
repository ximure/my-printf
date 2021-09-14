/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_star_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:01:36 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 20:42:52 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_star_handler(const char *format, int *i, va_list args)
{
	int a;

	a = *i;
	while (format[a] == '-' || format[a] == '.' || format[a] == '*' ||
	(format[a] >= '0' && format[a] <= '9'))
		a++;
	if (format[a] == 'd' || format[a] == 'i')
		ft_prec_digital_star(format, i, args, a);
	if (format[a] == 's')
		ft_prec_string_star(format, i, args, a);
}
