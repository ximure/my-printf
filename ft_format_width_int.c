/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_width_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:06:19 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 21:09:34 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_format_width_int_zeroes(int num)
{
	if (num < 0)
	{
		num = num * -1;
		write(1, "-", 1);
	}
	return (num);
}

void	ft_format_width_int(int num, const char *format, int *i)
{
	char	temp[11];
	int		width;
	int		a;

	a = 0;
	ft_bzero(temp, 11);
	while (format[*i] != 'd' && format[*i] != 'i' && format[*i] != 'u')
	{
		temp[a] = format[*i];
		a++;
		++*i;
	}
	width = ft_atoi(temp) - ft_numlen(num, num, format, i);
	if (temp[0] == '-')
		width = ((ft_atoi(temp) + ft_numlen(num, num, format, i)) * -1 + 1);
	if (temp[0] == '0')
		num = ft_format_width_int_zeroes(num);
	while (width != 0 && width > 0 && width-- && temp[0] != '-')
		temp[0] == '0' ? write(1, "0", 1) : write(1, " ", 1);
	if (format[*i] == 'd' || format[*i] == 'i')
		ft_format_digital(num);
	else if (format[*i] == 'u')
		ft_format_unsigned_digital(num);
	while (temp[0] == '-' && width--)
		write(1, " ", 1);
}
