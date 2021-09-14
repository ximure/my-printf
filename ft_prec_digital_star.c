/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_digital_star.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:31 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 21:03:45 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_digital_star_print_p(int w, int p, int num)
{
	int	p_n;

	p_n = p;
	p_n < 0 ? p_n -= p_n : p;
	if (w > 0)
		w = p > 0 ? w - ft_numlen_i(num) - p : w - ft_numlen_i(num);
	while (w >= 0 && w--)
		write(1, " ", 1);
	while (p >= 0 && p--)
		write(1, "0", 1);
	ft_format_digital(num);
	if (w < 0)
		w = w * -1 - ft_numlen_i(num) - p_n;
	while (w >= 0 && w--)
		write(1, " ", 1);
}

void	ft_prec_digital_star_print(int width, int precision, int num)
{
	int precision_negative;

	if (num < 0)
	{
		num *= -1;
		precision_negative = precision;
		if (precision_negative < 0)
			precision_negative -= precision_negative;
		if (width > 0)
			width = precision > 0 ? width - ft_numlen_i(num) - precision : width
			- ft_numlen_i(num);
		while (width >= 0 && width--)
			write(1, " ", 1);
		write(1, "-", 1);
		while (precision > 0 && precision--)
			write(1, "0", 1);
		ft_format_digital(num);
		if (width < 0)
			width = width * -1 - ft_numlen_i(num) - 2 - precision_negative;
		while (width >= 0 && width--)
			write(1, " ", 1);
	}
	else
		ft_prec_digital_star_print_p(width, precision, num);
}

int		ft_prec_digital_star_2(const char *format, int a)
{
	int	count_stars;

	count_stars = 0;
	while (format[a] != 'd' && format[a] != 'i')
	{
		if (format[a] == '*')
			count_stars++;
		a++;
	}
	return (count_stars);
}

void	ft_prec_digital_star(const char *format, int *i, va_list args, int a)
{
	int width;
	int precision;
	int count_stars;

	a = *i;
	count_stars = ft_prec_digital_star_2(format, a);
	if (count_stars == 1)
	{
		if (format[a - 1] == '*')
			precision = va_arg(args, int);
		else if (format[a - 1] != '*')
			width = va_arg(args, int);
	}
	if (count_stars == 2)
	{
		width = va_arg(args, int);
		precision = va_arg(args, int);
	}
	ft_prec_digital_star_print(width, precision, va_arg(args, int));
	while (format[*i] != 'd')
		++*i;
}
