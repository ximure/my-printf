/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:55:12 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 21:07:02 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format(const char *format, int *i, va_list args)
{
	int	a;

	a = *i;
	while (format[a] != '.' && format[a] != '\0')
		a++;
	if (format[*i] == 'd' || format[*i] == 'i')
		ft_format_digital(va_arg(args, int));
	else if (format[*i] == 's')
		ft_format_string(va_arg(args, char *));
	else if (format[*i] == 'c')
		ft_putchar(va_arg(args, int));
	else if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p')
		ft_format_x(va_arg(args, unsigned int), &*format, i);
	else if (format[*i] == 'u')
		ft_format_unsigned_digital(va_arg(args, unsigned int));
	else if (format[*i] == '%')
		ft_putchar('%');
	else if (format[a] == '.')
		ft_prec_handler(format, i, args);
	else if ((format[*i] >= '0' && format[*i] <= '9') || (format[*i] == '-'))
		ft_format_width(args, format, i);
	++*i;
}

void	ft_format_handler(const char *format, int *i, va_list args)
{
	while (format[*i] != '\0')
	{
		if (format[*i] == '%')
		{
			++*i;
			while (format[*i] == ' ')
				++*i;
			ft_format(format, i, args);
		}
		if (format[*i] != '%' && format[*i] != '\0')
		{
			write(1, &format[*i], 1);
			++*i;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		*p_i;
	va_list args;

	i = 0;
	p_i = &i;
	va_start(args, format);
	ft_format_handler(format, p_i, args);
	va_end(args);
	return (0);
}
