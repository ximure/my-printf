/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:05:24 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 18:05:02 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_x_print(int a, const char *hex)
{
	while (a >= 0)
	{
		write(1, &hex[a], 1);
		a--;
	}
}

void	ft_format_x(unsigned int dec, const char *format, int *i)
{
	int			remain;
	int			a;
	char		temp[16];

	a = 0;
	ft_bzero(temp, 16);
	if (dec == 0 && format[*i] != 'p')
		write(1, "0", 1);
	while (dec > 0)
	{
		remain = dec % 16;
		if (format[*i] == 'x' || format[*i] == 'p')
			temp[a] = remain < 10 ? (char)remain + 48 : (char)remain + 87;
		else if (format[*i] == 'X')
			temp[a] = remain < 10 ? (char)remain + 48 : (char)remain + 55;
		dec /= 16;
		a++;
	}
	--a;
	if (format[*i] == 'p' && dec == 0)
		write(1, "0x10", 4);
	format_x_print(a, temp);
}
