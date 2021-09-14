/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:12:00 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 21:33:29 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void	ft_prec_print_string(char *str, int length)
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

int		ft_prec_string(const char *format, int *i, char *str)
{
	int width;
	int precision;

	width = ft_prec_width(format, i);
	precision = ft_prec_precision(format, i);
	if (str == NULL)
		str = "(null)";
	if (precision == 0 && width == 0)
		return (0);
	if (width == 0 && precision > 0)
	{
		ft_prec_print_string(str, precision);
		return (0);
	}
	if (precision > ft_strlen(str) && width > 0)
		width = width - ft_strlen(str);
	else if (width > 0)
		width = width - precision;
	while (width > 0 && width--)
		write(1, " ", 1);
	ft_prec_print_string(str, precision);
	width <= 0 ? width *= -1 : width;
	width = precision > ft_strlen(str) ? width - ft_strlen(str) : width -
	precision;
	while (width > 0 && width--)
		write(1, " ", 1);
	return (0);
}