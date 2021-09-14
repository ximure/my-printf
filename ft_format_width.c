/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:06:19 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:10:57 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_width(va_list args, const char *format, int *i)
{
	int a;

	a = *i;
	while ((format[a] >= '0' && format[a] <= '9') || format[a] == '-')
		a++;
	if (format[a] == 'd' || format[a] == 'i' || format[a] == 'u')
		ft_format_width_int(va_arg(args, int), format, i);
	else if (format[a] == 's')
		ft_format_width_char(va_arg(args, char *), format, i);
	else if (format[a] == 'c')
		ft_format_width_character(va_arg(args, int), format, i);
	else if (format[a] == 'x' || format[a] == 'X' || format[a] == 'p')
		ft_format_width_x(va_arg(args, unsigned int), format, i);
	else if (format[a] == '%')
	{
		while (format[*i] != '%')
			++*i;
		write(1, "%", 1);
	}
}
