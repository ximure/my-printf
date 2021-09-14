/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_string_star.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 20:36:11 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 21:00:26 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_string_star_4(char *str, int length)
{
	int a;

	a = 0;
	while (length > 0 && a != ft_strlen(str))
	{
		write(1, &str[a], 1);
		a++;
		length--;
	}
}

int		ft_prec_string_star_3(int width, int precision, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (precision == 0 && width == 0)
		return (0);
	if (width == 0 && precision > 0)
	{
		ft_prec_string_star_4(str, precision);
		return (0);
	}
	if (precision > ft_strlen(str) && width > 0)
		width = width - ft_strlen(str);
	else if (width > 0)
		width = width - precision;
	while (width > 0 && width--)
		write(1, " ", 1);
	ft_prec_string_star_4(str, precision);
	width <= 0 ? width *= -1 : width;
	width = precision > ft_strlen(str) ? width - ft_strlen(str) : width -
	precision;
	while (width > 0 && width--)
		write(1, " ", 1);
	return (0);
}

int		ft_prec_string_star_2(const char *format, int a) //вторая, считает звезды
{
	int	count_stars;

	count_stars = 0;
	while (format[a] != 's')
	{
		if (format[a] == '*')
			count_stars++;
		a++;
	}
	return (count_stars);
}

void	ft_prec_string_star(const char *format, int *i, va_list args, int a) //самая первая функция, сюда отсылается с парс.
{
	int width;
	int precision;
	int count_stars;

	a = *i;
	count_stars = ft_prec_string_star_2(format, a);
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
	ft_prec_string_star_3(width, precision, va_arg(args, char *));
	while (format[*i] != 's')
		++*i;
}