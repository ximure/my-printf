/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_width_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:06:19 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:11:16 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_width_x(unsigned int dec, const char *format, int *i)
{
	char			temp[11];
	int				width;
	unsigned int	a;

	a = dec;
	ft_bzero(temp, 11);
	width = 1;
	while (a /= 16)
		width++;
	a = 0;
	while (format[*i] != 'x' && format[*i] != 'X' && format[*i] != 'p')
	{
		temp[a] = format[*i];
		++a;
		++*i;
	}
	if (format[*i] == 'p')
		width += 2;
	width = temp[0] == '-' ? (ft_atoi(temp) + width) * -1 + 2 :
	ft_atoi(temp) - width;
	while (width != 0 && width > 0 && width-- && temp[0] != '-')
		write(1, " ", 1);
	ft_format_x(dec, format, i);
	while (temp[0] == '-' && width-- && width > 0)
		write(1, " ", 1);
}
